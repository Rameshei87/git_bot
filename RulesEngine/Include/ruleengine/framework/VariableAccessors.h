// BaseTypes.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_BASETYPES_H
#define INC_BASETYPES_H

#include <string>
#include <map>
#include <ruleengine/framework/Expression.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/RuleException.h>
#include <ruleengine/framework/UnaryOperation.h>
#include <ruleengine/framework/ParseContext.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/VariableCreator.h>

/*********************************************************************
#    File        :  BaseTypes.h
#    Abstract    :  This file provides template classes for constants 
#                   and variables.
#    Date        :  01 May, 2007
#    Author(s)   :  Bhanu
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI        Edited by        Date            Area Edited
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/


//////////////////////////////////////////////////////////////////////
//
// This is a template class used to create a creator functor for an 
// operation.
//
//////////////////////////////////////////////////////////////////////
namespace ruleengine
{
class ExpressionCreator;
template <class Impl, class Type>
uint_16 variableTypeIndex()
{
    RULEENGINE_STACK_TRACE_ENTRY
    static uint_16 typeIndex = MemoryPool::getInstance().addTypeCreator( new PrimitiveVariableCreator<Impl> );

    RULEENGINE_STACK_TRACE_EXIT
    return typeIndex;
}


//////////////////////////////////////////////////////////////////////
// 
// This is a template class used to create Get Variable 
//
//////////////////////////////////////////////////////////////////////
template<class Impl, class Type>
class GetVariable : public Expression<Type>
{
private:
    enum
    {
        SCOPE_GLOBAL,
        SCOPE_RULE,
    };

    uint_16 _index;
    uint_16 _scope; 
public:
    //////////////////////////////////////////////////////////////////////
    //
    // Default Constructor
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : ---
    //    Paramters     : A pointer to DOMElement. 
    //                    The constructor gets the value attribute of this 
    //                    node to populate _value
    //
    //////////////////////////////////////////////////////////////////////
    GetVariable(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        std::string name = XercesHelpers::getStringAttributeValue(p,"name");
        if( name.length() > 2 && name[0] == '?' &&  name[1] == '?')
        {
           _scope = SCOPE_GLOBAL;
           ParseContext::VarIndexMap::iterator iter = context->globalVariables.find(name);
           if(iter == context->globalVariables.end())
           {
               RULEENGINE_STACK_TRACE_EXIT
               throw RuleException("Variable Not Found");
           }
           else
           {
               if( iter->second.first != variableTypeIndex<Impl,Type>() )
               {
                   RULEENGINE_STACK_TRACE_EXIT
                   throw RuleException("Variable Type Mismatch");
               }
               _index = iter->second.second;
           }
        }
        else if( name.length() > 1 && name[0] == '?' )
        {
           _scope = SCOPE_RULE;
           ParseContext::VarIndexMap::iterator iter = context->ruleVariables.find(name);
           if(iter == context->ruleVariables.end())
           {
               RULEENGINE_STACK_TRACE_EXIT
               throw RuleException("Variable Not Found");
           }
           else
           {
               if( iter->second.first != variableTypeIndex<Impl,Type>() )
               {
                   RULEENGINE_STACK_TRACE_EXIT
                   throw RuleException("Variable Type Mismatch");
               }
               _index = iter->second.second;
           }
        }
        else
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Variable Not Found");
        }
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////////
    //
    // evaluate function is used to evaluate the rule.
    // Parameters : a ruleengine pointer.
    //
    //////////////////////////////////////////////////////////////////////////
    Type evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        if(_scope == SCOPE_GLOBAL)
        {
            Impl *impl = dynamic_cast<Impl *>(engine->getGlobalVariables()->variable[ variableTypeIndex<Impl,Type>() ][_index]);
            if(!impl)
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException("Variable Not Found");
            }
            return impl->get();
        }

        else if(_scope == SCOPE_RULE)
        {
            Impl *impl = dynamic_cast<Impl *>(engine->getRuleVariables()->variable[ variableTypeIndex<Impl,Type>() ][_index]);
            if(!impl)
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException("Variable Not Found");
            }
            return impl->get();
        }
        else
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Invalid scope found");
        }
        RULEENGINE_STACK_TRACE_EXIT
    }

};

//////////////////////////////////////////////////////////////////////
// 
// This is a template class used to create Set Variable 
//
//////////////////////////////////////////////////////////////////////
template<class Impl, class Type>
class SetVariable 
    : public VoidExpression, 
      public UnaryOperation< Expression<Type> >
{
private:
    enum
    {
        SCOPE_GLOBAL,
        SCOPE_RULE,
    };

    uint_16 _index;
    uint_16 _scope; 
public:

    //////////////////////////////////////////////////////////////////////
    //
    // Default Constructor
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : ---
    //    Paramters     : A pointer to DOMElement. 
    //                    The constructor gets the value attribute of this 
    //                    node to populate _value
    //
    //////////////////////////////////////////////////////////////////////
    SetVariable(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
        : UnaryOperation< Expression<Type> >( p, context )
    {
        RULEENGINE_STACK_TRACE_ENTRY
        variableTypeIndex<Impl,Type>();
        std::string name = XercesHelpers::getStringAttributeValue(p,"name");
        if( name.length() > 2 && name[0] == '?' &&  name[1] == '?')
        {
           _scope = SCOPE_GLOBAL;
           ParseContext::VarIndexMap::iterator iter = context->globalVariables.find(name);
           if(iter == context->globalVariables.end())
           {
               RULEENGINE_STACK_TRACE_EXIT
               throw RuleException("Variable Not Found");
           }
           else
           {
               if( iter->second.first != variableTypeIndex<Impl,Type>() )
               {
                   RULEENGINE_STACK_TRACE_EXIT
                   throw RuleException("Variable Type Mismatch");
               }
               _index = iter->second.second;
           }
        }
        else if( name.length() > 1 && name[0] == '?' )
        {
           _scope = SCOPE_RULE;
           ParseContext::VarIndexMap::iterator iter = context->ruleVariables.find(name);
           if(iter == context->ruleVariables.end())
           {
               RULEENGINE_STACK_TRACE_EXIT
               throw RuleException("Variable Not Found");
           }
           else
           {
               if( iter->second.first != variableTypeIndex<Impl,Type>() )
               {
                   RULEENGINE_STACK_TRACE_EXIT
                   throw RuleException("Variable Type Mismatch");
               }
               _index = iter->second.second;
           }
        }
        else
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Variable Not Found");
        }
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////////
    //
    // evaluate function is used to evaluate the rule.
    // Parameters : a ruleengine pointer.
    //
    //////////////////////////////////////////////////////////////////////////
    void evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        if(_scope == SCOPE_GLOBAL)
        {
            Impl *impl = dynamic_cast<Impl *>(engine->getGlobalVariables()->variable[ variableTypeIndex<Impl,Type>() ][_index]);
            if(!impl)
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException("Variable Not Found");
            }
            
            impl->set( this->operand1->evaluate(engine) );
        }

        else if(_scope == SCOPE_RULE)
        {
            Impl *impl = dynamic_cast<Impl *>(engine->getRuleVariables()->variable[ variableTypeIndex<Impl,Type>() ][_index]);
            if(!impl)
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException("Variable Not Found");
            }

            impl->set( this->operand1->evaluate(engine) );
        }
        else
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Invalid scope found");
        }
        RULEENGINE_STACK_TRACE_EXIT
    }

};

class DeclareExpression : public ExpressionBase
{

public:

    virtual void evaluateAny(RuleEngine *engine){}

    virtual uint_16 getTypeIndex() = 0;

};

//////////////////////////////////////////////////////////////////////
// 
// This expression returns the typeIndex of a variable.
// The index returned would be used in GetVariable, SetVariable and
// also during invalidation of variables ( ruleVariables are 
// invalidated after a rule is fired and globalVariables are 
// invalidated after initial packet is processed )
//
//////////////////////////////////////////////////////////////////////
template<class Impl, class Type>
class DeclareVariable : public DeclareExpression
{
private:
    uint_16 _typeIndex;
public:

    //////////////////////////////////////////////////////////////////////
    //
    // Default Constructor
    //
    //////////////////////////////////////////////////////////////////////
    //
    // Parameters:
    //      See ExpressionCreator::ExpressionCreator()
    //
    //////////////////////////////////////////////////////////////////////
    DeclareVariable(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _typeIndex = variableTypeIndex<Impl,Type>();
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////////
    //
    // See Expression::evaluate()
    //
    //////////////////////////////////////////////////////////////////////////
    uint_16 getTypeIndex()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        return _typeIndex;
        RULEENGINE_STACK_TRACE_EXIT
    }

};

};
#endif //INC_BASETYPES_H

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
