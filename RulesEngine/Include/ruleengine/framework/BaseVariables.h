//BaseVariables.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_BASEVARIABLES_H
#define INC_BASEVARIABLES_H

#include<string>
#include<ABL_DateTime.h>
#include<ABL_Date.h>
#include<ruleengine/framework/Types.h>
#include<ruleengine/framework/VariableImplementation.h>
/*********************************************************************
#    File        :  BaseVariables.h
#    Abstract    :  Implementation of basic variables.
#    Date        :  14 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI   Edited by    Date              Area Edited
#
#
======================================================================
#    Libraries   :  
*********************************************************************/
namespace ruleengine
{

typedef PrimitiveVariableImplementation<char> CharacterVariableImplementation;
typedef PrimitiveVariableImplementation<std::string> StringVariableImplementation;
typedef PrimitiveVariableImplementation<int_16> Int16VariableImplementation;
typedef PrimitiveVariableImplementation<int_32> Int32VariableImplementation;
typedef PrimitiveVariableImplementation<int_64> Int64VariableImplementation;
typedef PrimitiveVariableImplementation<uint_16> Uint16VariableImplementation;
typedef PrimitiveVariableImplementation<uint_32> Uint32VariableImplementation;
typedef PrimitiveVariableImplementation<uint_64> Uint64VariableImplementation;
typedef PrimitiveVariableImplementation<float> FloatVariableImplementation;
typedef PrimitiveVariableImplementation<double> DoubleVariableImplementation;
typedef PrimitiveVariableImplementation<bool> BoolVariableImplementation;
typedef PrimitiveVariableImplementation<ABL_DateTime> DateTimeVariableImplementation;
typedef PrimitiveVariableImplementation<ABL_Date> DateVariableImplementation;



};
#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

