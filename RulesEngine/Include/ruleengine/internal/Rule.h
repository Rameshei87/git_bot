// Rule.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_RULE_H
#define INC_RULE_H

#include <list>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/Types.h>
/*********************************************************************
#   File        :   Rule.h
#   Abstract    :   Implemetation of Rule.
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
class XERCES_CPP_NAMESPACE::DOMNode;
class XERCES_CPP_NAMESPACE::DOMElement;

namespace ruleengine
{
class Condition;
class Action;
class ParseContext;

/////////////////////////////////////////////////////////////////////
//  
//  This class is instantiated when <packet> node encounters
//  a <rule> node in the xml document and then it pushed the 
//  rule into a list.
//
//////////////////////////////////////////////////////////////////////

//##ModelId=46308204031C
class Rule
{
  public:

    /////////////////////////////////////////////////////////////////////
    //
    //  This constructs a rule from a DOMElement* pointing to a <rule> 
    //  XML tag and a ParseContext and then identifies its children, eg
    //  Condition, Action, Declare Variable and construct the respective.
    //  This also set the value of some attributes of the rule tag, eg
    //  multi-occurrent, consume-input, name, id etc.
    //
    //  If the child is a declare variable then it map it in the local
    //  as well as in the RuleVariable map and determines the maximum  
    //  occurence of each datatype.
    //  If its a condition then it will create an object of it and evaluate
    //  its value. If the value is true then it will create an object of 
    //  each action and will evaluate it.
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
    //##ModelId=46383E28008C
    Rule(XERCES_CPP_NAMESPACE::DOMElement *element, ParseContext *context);


    /////////////////////////////////////////////////////////////////////
    //
    //  The destructor releases the Condition and each Action in a list.
    //  
    ////////////////////////////////////////////////////////////////////
    ~Rule();


    /////////////////////////////////////////////////////////////////////
    //
    //  This funtion is used to retrieve the value of the attribute Id 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Returns :
    //  uint_32
    //                 Id of the packet.
    //                  
    ////////////////////////////////////////////////////////////////////
    uint_32 getId()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _id;
    }

    /////////////////////////////////////////////////////////////////////
    //
    //  This funtion is used to retrieve the value of the attribute Name 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Returns :
    //  std::string
    //                 Name of the packet.
    //                  
    ////////////////////////////////////////////////////////////////////
    std::string  getName()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _name;
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
    //              If the rule fires then it will return true
    //
    //  Parameters :
    //  RuleEngine *engine
    //
    ////////////////////////////////////////////////////////////////////

    //##ModelId=463094A502EE
    bool evaluate(RuleEngine *engine);

    
    /////////////////////////////////////////////////////////////////////
    //
    //  If this is false, the rule does not fire more than once
    //  
    ////////////////////////////////////////////////////////////////////
    //##ModelId=4638232102CE
    bool multiOccurrent;
    ///////////////////////////////////////////////////////////////////////
    //
    //  The input will be consumed if it set to true when a rule is fired
    //  
    ///////////////////////////////////////////////////////////////////////
    //##ModelId=4638235800FA
    bool consumeInput;                   
  private:
    ///////////////////////////////////////////////////////////////////////
    //
    //  The child of the rule
    //  
    ///////////////////////////////////////////////////////////////////////
    //##ModelId=463093A60128
    Condition *_condition;  
    ///////////////////////////////////////////////////////////////////////
    //
    //  List of Actions are children of the rule
    //  
    ///////////////////////////////////////////////////////////////////////
    //##ModelId=463093C301F4
    std::list< Action * > _actions;   
    ///////////////////////////////////////////////////////////////////////
    //
    //  Name of the rule 
    //  
    ///////////////////////////////////////////////////////////////////////
    std::string _name;                     
    ///////////////////////////////////////////////////////////////////////
    //
    //  Id of the rule
    //  
    ///////////////////////////////////////////////////////////////////////
    uint_32 _id;                           
    ///////////////////////////////////////////////////////////////////////
    //
    //  To check whether RuleVariables are used
    //  
    ///////////////////////////////////////////////////////////////////////
    bool _usesRuleVariable;                

    /////////////////////////////////////////////////////////////////////
    //
    //  A list of indexes for variables that this rule uses
    //  The pair holds two int_16s - a type index and a variable index
    //  
    ////////////////////////////////////////////////////////////////////
    std::list< std::pair<uint_16, uint_16> > varIndexes;
    typedef std::list< std::pair<uint_16, uint_16> > VarIndexList;
    typedef std::pair<uint_16, uint_16> VarIndexPair;
};

};

#endif 
/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

