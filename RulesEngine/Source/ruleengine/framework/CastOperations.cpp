// CastOperations.cpp
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/CastOperations.h>
#include <ruleengine/framework/ExpressionCreator.h>
/*********************************************************************
#    File        :  CastOperations.cpp
#    Abstract    :  Implementation of Cast Operations.
#    Date        :  08 Sep, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI   Edited by    Date           Area Edited
#
#    1    Sangeeta   03 Sep, 2007       New preparation
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/

namespace ruleengine
{

//////////////////////////////////////////////////////////////////////////
//
//  This funtion registers Cast Operations in the ExpressionFactory.
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
void registerCastOperations()
{
    RULEENGINE_STACK_TRACE_ENTRY
    ExpressionFactory* factory = &ExpressionFactory::getInstance();
    factory->registerExpression("cast-double-to-float", new PrimitiveCreator<Cast<double,float> >());
    factory->registerExpression("cast-double-to-unsignedinteger64", new PrimitiveCreator<Cast<double,uint_64> >());
    factory->registerExpression("cast-double-to-integer64", new PrimitiveCreator<Cast<double,int_64> >());
    factory->registerExpression("cast-double-to-unsignedinteger32", new PrimitiveCreator<Cast<double,uint_32> >());
    factory->registerExpression("cast-double-to-integer32", new PrimitiveCreator<Cast<double,int_32> >());
    factory->registerExpression("cast-double-to-unsignedinteger16", new PrimitiveCreator<Cast<double,uint_16> >());
    factory->registerExpression("cast-double-to-integer16", new PrimitiveCreator<Cast<double,int_16> >());
    factory->registerExpression("cast-float-to-double", new PrimitiveCreator<Cast<float,double> >());
    factory->registerExpression("cast-float-to-unsignedinteger64", new PrimitiveCreator<Cast<float,uint_64> >());
    factory->registerExpression("cast-float-to-integer64", new PrimitiveCreator<Cast<float,int_64> >());
    factory->registerExpression("cast-float-to-unsignedinteger32", new PrimitiveCreator<Cast<float,uint_32> >());
    factory->registerExpression("cast-float-to-integer32", new PrimitiveCreator<Cast<float,int_32> >());
    factory->registerExpression("cast-float-to-unsignedinteger16", new PrimitiveCreator<Cast<float,uint_16> >());
    factory->registerExpression("cast-float-to-integer16", new PrimitiveCreator<Cast<float,int_16> >());
    factory->registerExpression("cast-unsignedinteger64-to-double", new PrimitiveCreator<Cast<uint_64,double> >());
    factory->registerExpression("cast-unsignedinteger64-to-float", new PrimitiveCreator<Cast<uint_64,float> >());
    factory->registerExpression("cast-unsignedinteger64-to-integer64", new PrimitiveCreator<Cast<uint_64,int_64> >());
    factory->registerExpression("cast-unsignedinteger64-to-unsignedinteger32", new PrimitiveCreator<Cast<uint_64,uint_32> >());
    factory->registerExpression("cast-unsignedinteger64-to-integer32", new PrimitiveCreator<Cast<uint_64,int_32> >());
    factory->registerExpression("cast-unsignedinteger64-to-unsignedinteger16", new PrimitiveCreator<Cast<uint_64,uint_16> >());
    factory->registerExpression("cast-unsignedinteger64-to-integer16", new PrimitiveCreator<Cast<uint_64,int_16> >());
    factory->registerExpression("cast-integer64-to-double", new PrimitiveCreator<Cast<int_64,double> >());
    factory->registerExpression("cast-integer64-to-float", new PrimitiveCreator<Cast<int_64,float> >());
    factory->registerExpression("cast-integer64-to-unsignedinteger64", new PrimitiveCreator<Cast<int_64,uint_64> >());
    factory->registerExpression("cast-integer64-to-unsignedinteger32", new PrimitiveCreator<Cast<int_64,uint_32> >());
    factory->registerExpression("cast-integer64-to-integer32", new PrimitiveCreator<Cast<int_64,int_32> >());
    factory->registerExpression("cast-integer64-to-unsignedinteger16", new PrimitiveCreator<Cast<int_64,uint_16> >());
    factory->registerExpression("cast-integer64-to-integer16", new PrimitiveCreator<Cast<int_64,int_16> >());
    factory->registerExpression("cast-unsignedinteger32-to-double", new PrimitiveCreator<Cast<uint_32,double> >());
    factory->registerExpression("cast-unsignedinteger32-to-float", new PrimitiveCreator<Cast<uint_32,float> >());
    factory->registerExpression("cast-unsignedinteger32-to-unsignedinteger64", new PrimitiveCreator<Cast<uint_32,uint_64> >());
    factory->registerExpression("cast-unsignedinteger32-to-integer64", new PrimitiveCreator<Cast<uint_32,int_64> >());
    factory->registerExpression("cast-unsignedinteger32-to-integer32", new PrimitiveCreator<Cast<uint_32,int_32> >());
    factory->registerExpression("cast-unsignedinteger32-to-unsignedinteger16", new PrimitiveCreator<Cast<uint_32,uint_16> >());
    factory->registerExpression("cast-unsignedinteger32-to-integer16", new PrimitiveCreator<Cast<uint_32,int_16> >());
    factory->registerExpression("cast-integer32-to-double", new PrimitiveCreator<Cast<int_32,double> >());
    factory->registerExpression("cast-integer32-to-float", new PrimitiveCreator<Cast<int_32,float> >());
    factory->registerExpression("cast-integer32-to-unsignedinteger64", new PrimitiveCreator<Cast<int_32,uint_64> >());
    factory->registerExpression("cast-integer32-to-integer64", new PrimitiveCreator<Cast<int_32,int_64> >());
    factory->registerExpression("cast-integer32-to-unsignedinteger32", new PrimitiveCreator<Cast<int_32,uint_32> >());
    factory->registerExpression("cast-integer32-to-unsignedinteger16", new PrimitiveCreator<Cast<int_32,uint_16> >());
    factory->registerExpression("cast-integer32-to-integer16", new PrimitiveCreator<Cast<int_32,int_16> >());
    factory->registerExpression("cast-unsignedinteger16-to-double", new PrimitiveCreator<Cast<uint_16,double> >());
    factory->registerExpression("cast-unsignedinteger16-to-float", new PrimitiveCreator<Cast<uint_16,float> >());
    factory->registerExpression("cast-unsignedinteger16-to-unsignedinteger64", new PrimitiveCreator<Cast<uint_16,uint_64> >());
    factory->registerExpression("cast-unsignedinteger16-to-integer64", new PrimitiveCreator<Cast<uint_16,int_64> >());
    factory->registerExpression("cast-unsignedinteger16-to-unsignedinteger32", new PrimitiveCreator<Cast<uint_16,uint_32> >());
    factory->registerExpression("cast-unsignedinteger16-to-integer32", new PrimitiveCreator<Cast<uint_16,int_32> >());
    factory->registerExpression("cast-unsignedinteger16-to-integer16", new PrimitiveCreator<Cast<uint_16,int_16> >());
    factory->registerExpression("cast-integer16-to-double", new PrimitiveCreator<Cast<int_16,double> >());
    factory->registerExpression("cast-integer16-to-float", new PrimitiveCreator<Cast<int_16,float> >());
    factory->registerExpression("cast-integer16-to-unsignedinteger64", new PrimitiveCreator<Cast<int_16,uint_64> >());
    factory->registerExpression("cast-integer16-to-integer64", new PrimitiveCreator<Cast<int_16,int_64> >());
    factory->registerExpression("cast-integer16-to-unsignedinteger32", new PrimitiveCreator<Cast<int_16,uint_32> >());
    factory->registerExpression("cast-integer16-to-integer32", new PrimitiveCreator<Cast<int_16,int_32> >());
    factory->registerExpression("cast-integer16-to-unsignedinteger16", new PrimitiveCreator<Cast<int_16,uint_16> >());
    RULEENGINE_STACK_TRACE_EXIT
}

};
/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
