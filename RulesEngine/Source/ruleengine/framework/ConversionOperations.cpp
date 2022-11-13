// ConversionOperations.cpp
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/ConversionOperations.h>
#include <ruleengine/framework/ExpressionCreator.h>
/*********************************************************************
#    File        :  ConversionOperations.cpp
#    Abstract    :  Implementation of Conversion Operations.
#    Date        :  03 Sep, 2007 
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI   Edited by    Date           Area Edited
#
#    1    Sangeeta   08 Sep, 2007       New preparation
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/

namespace ruleengine
{

//////////////////////////////////////////////////////////////////////////
//
//  This funtion registers ConversionOperations in the ExpressionFactory.
//
//  This function allocates new Creator objects and registers their pointers
//  in the map.
// 
//  The ExpressionFactory should free these objects in its destructor
//  by the caller function.
//
//  This function should be called only once in the lifetime of an
//  applicaton.
//
/////////////////////////////////////////////////////////////////////////
void registerConversionOperations()
{
    RULEENGINE_STACK_TRACE_ENTRY
    ExpressionFactory* factory = &ExpressionFactory::getInstance();
    factory->registerExpression("convert-string-to-integer64", new PrimitiveCreator<ConversionStringToInteger64 >());
    factory->registerExpression("convert-datetime-to-seconds", new PrimitiveCreator<ConversionDateTimeToSeconds >());
    RULEENGINE_STACK_TRACE_EXIT
}

};
/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

