// LogicalOperations.h
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/framework/ExpressionCreator.h>
/*********************************************************************
#    File        :  LogicalOperations.cpp
#    Abstract    :  Implementation of LogicalOperations.
#    Date        :  01 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI Edited by    Date           Area Edited
#
#    1  Sangeeta  04-May-2007  New Preparation
#
#    2  Kishore   25-May-2007  registerLogicalOperations() was 
#                              taking map as its parameter and filling it.
#                              Used ExpressionFactory::register instead
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/

namespace ruleengine
{

//////////////////////////////////////////////////////////////////////////
//
//  This funtion registers LogicalOperations in the ExpressionFactory.
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
void registerLogicalOperations()
{
    RULEENGINE_STACK_TRACE_ENTRY
    ExpressionFactory* factory = &ExpressionFactory::getInstance();
    factory->registerExpression( "and", new PrimitiveCreator<And >() );
    factory->registerExpression( "or", new PrimitiveCreator<Or >() );
    factory->registerExpression( "not", new PrimitiveCreator<Not >() );
    RULEENGINE_STACK_TRACE_EXIT
}
};
/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
