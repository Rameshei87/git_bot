#include <ruleengine/framework/VariableAccessors.h>
#include <ruleengine/framework/BaseVariables.h>
#include <ruleengine/engine/RuleEngine.h>

/*********************************************************************
#    File        :  BaseTypes.cpp
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
#    SI Edited by    Date            Area Edited
#
#    2  Kishore   25-May-2007  registerBaseTypes() was 
#                              taking map as its parameter and filling it.
#                              Used ExpressionFactory::register instead
======================================================================
#    Libraries   :  xerces
*********************************************************************/




namespace ruleengine
{

//Constants
//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a Character Constant
// This class represents a Character Constant. The string is set on 
// construction and returned in evaluate.
//
////////////////////////////////////////////////////////////////////// 
class CharacterConstant : public CharacterExpression
{
private:
    char _value;
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
    CharacterConstant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getStringAttributeValue(p,"value")[0];
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : string
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    char evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};

//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a String Constant
// This class represents a String Constant. The string is set on 
// construction and returned in evaluate.
//
////////////////////////////////////////////////////////////////////// 
class StringConstant : public StringExpression
{
private:
    std::string _value;
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
    StringConstant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getStringAttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : string
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    std::string evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};

class DateTimeConstant : public DateTimeExpression
{
private:
    ABL_DateTime _value;
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
    DateTimeConstant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getDateTimeAttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : ABL_DateTime
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    ABL_DateTime evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};


class DateConstant : public DateExpression
{
private:
    ABL_Date _value;
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
    DateConstant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getDateAttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : ABL_DateTime
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    ABL_Date evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};



//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a Integer16Constant
// This class represents a Integer16Constant. The Integer16Constant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class Integer16Constant : public Integer16Expression
{

private:
    int_16 _value;

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
    ///////////////////////////////////////////////////////////////////////
    Integer16Constant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getInt16AttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : int_16
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    int_16 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};



//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a Integer32Constant
// This class represents a Integer32Constant. The Integer32Constant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class Integer32Constant : public Integer32Expression
{

private:
    int_32 _value;

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
    Integer32Constant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getInt32AttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : int_32
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    int_32 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};

//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a Integer64Constant
// This class represents a Integer64Constant. The Integer64Constant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class Integer64Constant : public Integer64Expression
{

private:
    int_64 _value;

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
    Integer64Constant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getInt64AttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : int_64
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    int_64 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};

//Unsigned Integer Constants

//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a Integer16Constant
// This class represents a Integer16Constant. The Integer16Constant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class UnsignedInteger16Constant : public UnsignedInteger16Expression
{

private:
    uint_16 _value;

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
    ///////////////////////////////////////////////////////////////////////
    UnsignedInteger16Constant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getUint16AttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : string
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    uint_16 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};



//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a Integer32Constant
// This class represents a Integer32Constant. The Integer32Constant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class UnsignedInteger32Constant : public UnsignedInteger32Expression
{

private:
    uint_32 _value;

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
    UnsignedInteger32Constant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getUint32AttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : int_32
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    uint_32 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};

//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a UnsignedInteger64Constant
// This class represents a Integer64Constant. The UnsignedInteger64Constant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class UnsignedInteger64Constant : public UnsignedInteger64Expression
{

private:
    uint_64 _value;

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
    UnsignedInteger64Constant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getUint64AttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : int_64
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    uint_64 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};

//Boolean
///////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a BooleanConstant
// This class represents a BooleanConstant. The BooleanConstant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class BooleanConstant : public BooleanExpression
{

private:
    bool _value;

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
    BooleanConstant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getBooleanAttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : bool
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    bool evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};

//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a FloatConstant
// This class represents a FloatConstant. The FloatConstant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class FloatConstant : public FloatExpression
{

private:
    float _value;

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
    FloatConstant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getFloatAttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : float
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    float evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};


//////////////////////////////////////////////////////////////////////
//
// This class provides methods to evaluate a DoubleConstant
// This class represents a DoubleConstant. The DoubleConstant 
// is set on construction and returned in evaluate.
//
//////////////////////////////////////////////////////////////////////
class DoubleConstant : public DoubleExpression
{

private:
    double _value;

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
    DoubleConstant(XERCES_CPP_NAMESPACE::DOMElement* p, ParseContext *context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _value = XercesHelpers::getDoubleAttributeValue(p,"value");
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns _value populated by the constructor.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //    Return value  : double
    //    Paramters     : The RuleEngine pointer.
    //
    //////////////////////////////////////////////////////////////////////
    double evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _value;
    }
};


//////////////////////////////////////////////////////////////////////////////
//
// This function registers constants and variables for basic types
//
//////////////////////////////////////////////////////////////////////////////
void registerBaseTypes()
{
    RULEENGINE_STACK_TRACE_ENTRY
    ExpressionFactory* factory = &ExpressionFactory::getInstance();
    //Constants
    factory->registerExpression( "character-constant", new PrimitiveCreator<CharacterConstant >() );
    factory->registerExpression( "string-constant", new PrimitiveCreator<StringConstant >() );
    factory->registerExpression( "integer16-constant", new PrimitiveCreator<Integer16Constant >() );
    factory->registerExpression( "integer32-constant", new PrimitiveCreator<Integer32Constant >() );
    factory->registerExpression( "integer64-constant", new PrimitiveCreator<Integer64Constant >() );
    factory->registerExpression( "unsigned-integer16-constant", new PrimitiveCreator<UnsignedInteger16Constant >() );
    factory->registerExpression( "unsigned-integer32-constant", new PrimitiveCreator<UnsignedInteger32Constant >() );
    factory->registerExpression( "unsigned-integer64-constant", new PrimitiveCreator<UnsignedInteger64Constant >() );
    factory->registerExpression( "boolean-constant", new PrimitiveCreator<BooleanConstant >() );
	
	//std::map< std::string , ExpressionCreator*  >::iterator mapIter=factory->creator.find("boolean-constant");
	//XERCES_CPP_NAMESPACE::DOMElement *node = NULL;
	//ParseContext *parseContext = NULL;
	//(*mapIter->second)(node, parseContext);


    factory->registerExpression( "float-constant", new PrimitiveCreator<FloatConstant >() );
    factory->registerExpression( "double-constant", new PrimitiveCreator<DoubleConstant >() );
    factory->registerExpression( "datetime-constant", new PrimitiveCreator<DateTimeConstant >() );
    factory->registerExpression( "date-constant", new PrimitiveCreator<DateConstant >() );

    //Variables
    factory->registerExpression( "character-variable", new PrimitiveCreator< GetVariable<CharacterVariableImplementation,char> >() );
    factory->registerExpression( "set-character-variable", new PrimitiveCreator< SetVariable<CharacterVariableImplementation,char> >() );
    factory->registerExpression( "string-variable", new PrimitiveCreator< GetVariable<StringVariableImplementation,std::string> >() );
    factory->registerExpression( "set-string-variable", new PrimitiveCreator< SetVariable<StringVariableImplementation,std::string> >() );
    factory->registerExpression( "integer16-variable", new PrimitiveCreator< GetVariable<Int16VariableImplementation,int_16> >() );
    factory->registerExpression( "set-integer16-variable", new PrimitiveCreator< SetVariable<Int16VariableImplementation,int_16> >() );
    factory->registerExpression( "integer32-variable", new PrimitiveCreator< GetVariable<Int32VariableImplementation,int_32> >() );
    factory->registerExpression( "set-integer32-variable", new PrimitiveCreator< SetVariable<Int32VariableImplementation,int_32> >() );
    factory->registerExpression( "integer64-variable", new PrimitiveCreator< GetVariable<Int64VariableImplementation,int_64> >() );
    factory->registerExpression( "set-integer64-variable", new PrimitiveCreator< SetVariable<Int64VariableImplementation,int_64> >() );
    factory->registerExpression( "unsigned-integer16-variable", new PrimitiveCreator< GetVariable<Uint16VariableImplementation,uint_16> >() );
    factory->registerExpression( "set-unsigned-integer16-variable", new PrimitiveCreator< SetVariable<Uint16VariableImplementation,uint_16> >() );
    factory->registerExpression( "unsigned-integer32-variable", new PrimitiveCreator< GetVariable<Uint32VariableImplementation,uint_32> >() );
    factory->registerExpression( "set-unsigned-integer32-variable", new PrimitiveCreator< SetVariable<Uint32VariableImplementation,uint_32> >() );
    factory->registerExpression( "unsigned-integer64-variable", new PrimitiveCreator< GetVariable<Uint64VariableImplementation,uint_64> >() );
    factory->registerExpression( "set-unsigned-integer64-variable", new PrimitiveCreator< SetVariable<Uint64VariableImplementation,uint_64> >() );
    factory->registerExpression( "float-variable", new PrimitiveCreator< GetVariable<FloatVariableImplementation,float> >() );
    factory->registerExpression( "set-float-variable", new PrimitiveCreator< SetVariable<FloatVariableImplementation,float> >() );
    factory->registerExpression( "double-variable", new PrimitiveCreator< GetVariable<DoubleVariableImplementation,double> >() );
    factory->registerExpression( "set-double-variable", new PrimitiveCreator< SetVariable<DoubleVariableImplementation,double> >() );
    factory->registerExpression( "boolean-variable", new PrimitiveCreator< GetVariable<BoolVariableImplementation,bool> >() );
    factory->registerExpression( "set-boolean-variable", new PrimitiveCreator< SetVariable<BoolVariableImplementation,bool> >() );
    factory->registerExpression( "datetime-variable", new PrimitiveCreator< GetVariable<DateTimeVariableImplementation,ABL_DateTime> >() );
    factory->registerExpression( "set-datetime-variable", new PrimitiveCreator< SetVariable<DateTimeVariableImplementation,ABL_DateTime> >() );
    factory->registerExpression( "set-date-variable", new PrimitiveCreator< SetVariable<DateVariableImplementation,ABL_Date> >() );


    factory->registerExpression( "declare-character-variable", new PrimitiveCreator< DeclareVariable<CharacterVariableImplementation,char> >() );
    factory->registerExpression( "declare-string-variable", new PrimitiveCreator< DeclareVariable<StringVariableImplementation,std::string> >() );
    factory->registerExpression( "declare-integer16-variable", new PrimitiveCreator< DeclareVariable<Int16VariableImplementation,int_16> >() );
    factory->registerExpression( "declare-integer32-variable", new PrimitiveCreator< DeclareVariable<Int32VariableImplementation,int_32> >() );
    factory->registerExpression( "declare-integer64-variable", new PrimitiveCreator< DeclareVariable<Int64VariableImplementation,int_64> >() );
    factory->registerExpression( "declare-unsigned-integer16-variable", new PrimitiveCreator< DeclareVariable<Uint16VariableImplementation,uint_16> >() );
    factory->registerExpression( "declare-unsigned-integer32-variable", new PrimitiveCreator< DeclareVariable<Uint32VariableImplementation,uint_32> >() );
    factory->registerExpression( "declare-unsigned-integer64-variable", new PrimitiveCreator< DeclareVariable<Uint64VariableImplementation,uint_64> >() );
    factory->registerExpression( "declare-float-variable", new PrimitiveCreator< DeclareVariable<FloatVariableImplementation,float> >() );
    factory->registerExpression( "declare-double-variable", new PrimitiveCreator< DeclareVariable<DoubleVariableImplementation,double> >() );
    factory->registerExpression( "declare-boolean-variable", new PrimitiveCreator< DeclareVariable<BoolVariableImplementation,bool> >() );
    factory->registerExpression( "declare-datetime-variable", new PrimitiveCreator< DeclareVariable<DateTimeVariableImplementation,ABL_DateTime> >() );
    factory->registerExpression( "declare-date-variable", new PrimitiveCreator< DeclareVariable<DateVariableImplementation,ABL_Date> >() );

    RULEENGINE_STACK_TRACE_EXIT
}

};
/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
