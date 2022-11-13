// Rule.cpp
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/Expression.h>
#include <ruleengine/internal/Rule.h>
#include <ruleengine/internal/Action.h>
#include <ruleengine/internal/Condition.h>
#include <ruleengine/engine/RuleException.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/ParseContext.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/framework/VariableImplementation.h>
#include <ruleengine/framework/VariableAccessors.h>

/*********************************************************************
#   File        :   Rule.cpp
#   Abstract    :   Implemetation of Rules.
#   Date        :   04 May, 2007
#   Author(s)   :   Sangeeta
#   Design      :  
#   References    
#   Module      :   RuleEngine
======================================================================
#   Revision History
======================================================================
#   SI          Edited by       Date        Area Edited
#
======================================================================
#   Libraries   :    xerces
*********************************************************************/
namespace ruleengine
{
/////////////////////////////////////////////////////////////////////
//
//  This constructs a rule from a DOMElement* pointing to a <rule> 
//  XML tag and a ParseContext and then identifies its children, eg
//  Condition, Action, Declare Variable and construct the respective.
//  This also set the value of some attributes of the rule tag, eg
//  multi-occurrent, consume-input, name, id etc.
//
//  Algorithm :     1> Retrieves the value of the attributes id, 
//                     name, multi-occurent and consume-input    
//                  2> For each child
//                     i>   If it is declare-variables then map it
//                          in the RuleVariables if valid.
//                     ii>  If it is condition then create an 
//                          object of it.
//                     iii> If it is action then add it in the list
//                          of actions.
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameters :
//  DOMElement *element
//              This should point to the <rule> tag. The constructor
//              traverses the tag and creates Condition and Action.
//
//  ParseContext *context
//              Used to set the maxRuleVariable.
//
////////////////////////////////////////////////////////////////////
Rule::Rule(XERCES_CPP_NAMESPACE::DOMElement *element, ParseContext *context)
{
    RULEENGINE_STACK_TRACE_ENTRY
    _id = 0;                       //Initialising Id to 0
    _usesRuleVariable = false;     //Initialising _usesRuleVariable 
    //get the value of the attributes multi-occurent and consume-input
    multiOccurrent=XercesHelpers::getBooleanAttributeValue(element,"multi-occurrent");
    consumeInput=XercesHelpers::getBooleanAttributeValue(element,"consume-input");

    XercesHelpers::getStringAttributeValue(element,"name",_name); 
   
    XercesHelpers::getUint32AttributeValue(element,"id",_id); 
    
    //For each child of Rule
    for( XERCES_CPP_NAMESPACE::DOMNode *child = element->getFirstChild(); child != NULL; child = child->getNextSibling() )
    {
        if( child->getNodeType() == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE )       //If it is a DOMElement
        {
            if(XercesHelpers::checkNodeName(child,"declare-variables"))     // If declare-variables is present
            {
                _usesRuleVariable = true;
                std::map<std::string,uint_16> typeCount;
                
                for( XERCES_CPP_NAMESPACE::DOMNode *grandChild = child->getFirstChild(); grandChild != NULL; grandChild = grandChild->getNextSibling() )        //for each child-node in declare-variables
                {
                    //Map each variables of different data types locally and maintain a counter for each data types
                    if(grandChild->getNodeType()== XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)     // If declare-variables is present
                    {
                        // Get the typeIndex
                        DeclareExpression *declExpr = ExpressionFactory::getInstance().createExpression<DeclareExpression>((XERCES_CPP_NAMESPACE::DOMElement*)grandChild, context);
                        uint_16 typeIndex = declExpr->getTypeIndex();
                        delete declExpr;

                        // Calculate varIndex - this index should be different for all variables of same type
                        uint_16 varIndex;

                        std::string varName = XercesHelpers::getStringAttributeValue(grandChild,"name");
                        std::string typeName = XercesHelpers::getNodeName(grandChild);

                        std::map<std::string,uint_16>::iterator iterType = typeCount.find(typeName);
                        if( iterType != typeCount.end() ) 
                        {
                            // If a variable of the type exists, increment the counter
                            iterType->second=iterType->second+1;
                            varIndex = iterType->second;
                        }
                        else
                        {
                            // If a variable of the type does not exist,
                            // start from 0
                            typeCount[typeName] = 0;
                            varIndex = 0;
                        }

                        //RuleVariables should starts with a single ? character
                        if( ( varName.length() < 2 ) || ( varName[0]!='?' ) || ( varName[1]=='?' ) )
                        {
                            RULEENGINE_STACK_TRACE_EXIT
                            throw RuleException("Invalid Variable Name");
                        }

                        // Set variable index in ParseContext::ruleVariables
                        context->ruleVariables[varName] = ParseContext::VarIndexPair(typeIndex,varIndex);
                        varIndexes.push_back(VarIndexPair(typeIndex,varIndex));
                    }
                }
                uint_32 max = 0;
                std::map<std::string,uint_16> :: iterator iter;
                //Finding the maximum occurence of a variable among all others in the local map 
                for(iter = typeCount.begin();iter!=typeCount.end();iter++)
                {
                    if(max < iter->second)
                    {
                        max = iter->second;
                    }
                }
                //Assigning the maximum occurence to maxRuleVariable of ParsrContext
                if(context->maxRuleVariables < max+1)
                {
                    context->maxRuleVariables = max+1;
                }
            }
            //If the child node is condition then create an instance of it
            else if(XercesHelpers::checkNodeName(child,"condition"))
            {
                _condition = new Condition((XERCES_CPP_NAMESPACE::DOMElement *)child,context);
            }
            //If the child node is action then create an instance of it
            else if(XercesHelpers::checkNodeName(child,"action"))
            {
                _actions.push_back(new Action( (XERCES_CPP_NAMESPACE::DOMElement *)child,context));
            }
        }
    }
    RULEENGINE_STACK_TRACE_EXIT
}


/////////////////////////////////////////////////////////////////////
//
//  The destructor releases the Condition and each Action in a list.
//  
////////////////////////////////////////////////////////////////////
Rule :: ~Rule()
{
    RULEENGINE_STACK_TRACE_ENTRY
    delete _condition;

    for(std::list<Action*>::iterator it = _actions.begin();
                                     it != _actions.end();
                                     it++
        )
    {
        delete (*it);
    }
    RULEENGINE_STACK_TRACE_EXIT
}


/////////////////////////////////////////////////////////////////////
//
//  This funtion is pushes each rule variables in a list. If the 
//  condition in a rule is evaluated to true then it evaluates each
//  action in it and finally pop out the rule variable from the list.
//  It returns true if the condition contains a valid expression.
//  
////////////////////////////////////////////////////////////////////
//
//  Returns :
//  bool            
//                  If the rule fires then it will return true
//  Parameters :
//  RuleEngine *engine
//
//////////////////////////////////////////////////////////////////////
//##ModelId=463094A502EE
bool Rule :: evaluate(RuleEngine *engine)
{   
    RULEENGINE_STACK_TRACE_ENTRY
    if(_usesRuleVariable == true)
    {
        engine->pushRuleVariable();
    }
    if( _condition->evaluate(engine) )
    {
        std::list< Action * > :: iterator iter;
        //for each action
        for(iter = _actions.begin();iter!=_actions.end();iter++)
        {
            (*iter)->execute(engine);
        }
        if(_usesRuleVariable == true)
        {
            VariableImplementation*** variables = engine->getRuleVariables()->variable;
            for( VarIndexList::iterator it = varIndexes.begin(); it != varIndexes.end(); it++)
            {
                variables[ it->first ][ it->second ]->invalidate();
            }
            engine->popRuleVariable();
        }
        RULEENGINE_STACK_TRACE_EXIT
        return true;
    }
    else
    {
        if(_usesRuleVariable == true)
        {
            VariableImplementation*** variables = engine->getRuleVariables()->variable;
            for( VarIndexList::iterator it = varIndexes.begin(); it != varIndexes.end(); it++)
            {
                variables[ it->first ][ it->second ]->invalidate();
            }
            engine->popRuleVariable();
        }
        RULEENGINE_STACK_TRACE_EXIT
        return false;
    }
}

};
