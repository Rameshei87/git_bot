// ComparisonOperations.cpp
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/ExpressionCreator.h>

/**********************************************************************
#    File        :  ComparisonOperations.cpp
#    Abstract    :  Implementation of ComparisonOperations.
#    Date        :  01 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
=======================================================================
#    Revision History
=======================================================================
#    SI Edited by    Date           Area Edited
#
#    1  Sangeeta  04-May-2007  New Preparation
#
#    2  Kishore   25-May-2007  registerComparisonOperations() was 
#                              taking map as its parameter and filling it.
#                              Used ExpressionFactory::register instead
#
=======================================================================
#    Libraries   :  xerces
**********************************************************************/

namespace ruleengine
{

//////////////////////////////////////////////////////////////////////////
//
//  This funtion registers ComparisonOperations in the ExpressionFactory.
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
void registerComparisonOperations()
{
    RULEENGINE_STACK_TRACE_ENTRY
    ExpressionFactory* factory = &ExpressionFactory::getInstance();
    factory->registerExpression( "equal-double-double", new PrimitiveCreator<Equal<double,double> >() );
    factory->registerExpression( "equal-double-float", new PrimitiveCreator<Equal<double,float> >() );
    factory->registerExpression( "equal-double-unsignedinteger64", new PrimitiveCreator<Equal<double,uint_64> >() );
    factory->registerExpression( "equal-double-integer64", new PrimitiveCreator<Equal<double,int_64> >() );
    factory->registerExpression( "equal-double-unsignedinteger32", new PrimitiveCreator<Equal<double,uint_32> >() );
    factory->registerExpression( "equal-double-integer32", new PrimitiveCreator<Equal<double,int_32> >() );
    factory->registerExpression( "equal-double-unsignedinteger16", new PrimitiveCreator<Equal<double,uint_16> >() );
    factory->registerExpression( "equal-double-integer16", new PrimitiveCreator<Equal<double,int_16> >() );
    factory->registerExpression( "equal-float-double", new PrimitiveCreator<Equal<float,double> >() );
    factory->registerExpression( "equal-float-float", new PrimitiveCreator<Equal<float,float> >() );
    factory->registerExpression( "equal-float-unsignedinteger64", new PrimitiveCreator<Equal<float,uint_64> >() );
    factory->registerExpression( "equal-float-integer64", new PrimitiveCreator<Equal<float,int_64> >() );
    factory->registerExpression( "equal-float-unsignedinteger32", new PrimitiveCreator<Equal<float,uint_32> >() );
    factory->registerExpression( "equal-float-integer32", new PrimitiveCreator<Equal<float,int_32> >() );
    factory->registerExpression( "equal-float-unsignedinteger16", new PrimitiveCreator<Equal<float,uint_16> >() );
    factory->registerExpression( "equal-float-integer16", new PrimitiveCreator<Equal<float,int_16> >() );
    factory->registerExpression( "equal-unsignedinteger64-double", new PrimitiveCreator<Equal<uint_64,double> >() );
    factory->registerExpression( "equal-unsignedinteger64-float", new PrimitiveCreator<Equal<uint_64,float> >() );
    factory->registerExpression( "equal-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<Equal<uint_64,uint_64> >() );
    factory->registerExpression( "equal-unsignedinteger64-integer64", new PrimitiveCreator<Equal<uint_64,int_64> >() );
    factory->registerExpression( "equal-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<Equal<uint_64,uint_32> >() );
    factory->registerExpression( "equal-unsignedinteger64-integer32", new PrimitiveCreator<Equal<uint_64,int_32> >() );
    factory->registerExpression( "equal-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<Equal<uint_64,uint_16> >() );
    factory->registerExpression( "equal-unsignedinteger64-integer16", new PrimitiveCreator<Equal<uint_64,int_16> >() );
    factory->registerExpression( "equal-integer64-double", new PrimitiveCreator<Equal<int_64,double> >() );
    factory->registerExpression( "equal-integer64-float", new PrimitiveCreator<Equal<int_64,float> >() );
    factory->registerExpression( "equal-integer64-unsignedinteger64", new PrimitiveCreator<Equal<int_64,uint_64> >() );
    factory->registerExpression( "equal-integer64-integer64", new PrimitiveCreator<Equal<int_64,int_64> >() );
    factory->registerExpression( "equal-integer64-unsignedinteger32", new PrimitiveCreator<Equal<int_64,uint_32> >() );
    factory->registerExpression( "equal-integer64-integer32", new PrimitiveCreator<Equal<int_64,int_32> >() );
    factory->registerExpression( "equal-integer64-unsignedinteger16", new PrimitiveCreator<Equal<int_64,uint_16> >() );
    factory->registerExpression( "equal-integer64-integer16", new PrimitiveCreator<Equal<int_64,int_16> >() );
    factory->registerExpression( "equal-unsignedinteger32-double", new PrimitiveCreator<Equal<uint_32,double> >() );
    factory->registerExpression( "equal-unsignedinteger32-float", new PrimitiveCreator<Equal<uint_32,float> >() );
    factory->registerExpression( "equal-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<Equal<uint_32,uint_64> >() );
    factory->registerExpression( "equal-unsignedinteger32-integer64", new PrimitiveCreator<Equal<uint_32,int_64> >() );
    factory->registerExpression( "equal-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<Equal<uint_32,uint_32> >() );
    factory->registerExpression( "equal-unsignedinteger32-integer32", new PrimitiveCreator<Equal<uint_32,int_32> >() );
    factory->registerExpression( "equal-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<Equal<uint_32,uint_16> >() );
    factory->registerExpression( "equal-unsignedinteger32-integer16", new PrimitiveCreator<Equal<uint_32,int_16> >() );
    factory->registerExpression( "equal-integer32-double", new PrimitiveCreator<Equal<int_32,double> >() );
    factory->registerExpression( "equal-integer32-float", new PrimitiveCreator<Equal<int_32,float> >() );
    factory->registerExpression( "equal-integer32-unsignedinteger64", new PrimitiveCreator<Equal<int_32,uint_64> >() );
    factory->registerExpression( "equal-integer32-integer64", new PrimitiveCreator<Equal<int_32,int_64> >() );
    factory->registerExpression( "equal-integer32-unsignedinteger32", new PrimitiveCreator<Equal<int_32,uint_32> >() );
    factory->registerExpression( "equal-integer32-integer32", new PrimitiveCreator<Equal<int_32,int_32> >() );
    factory->registerExpression( "equal-integer32-unsignedinteger16", new PrimitiveCreator<Equal<int_32,uint_16> >() );
    factory->registerExpression( "equal-integer32-integer16", new PrimitiveCreator<Equal<int_32,int_16> >() );
    factory->registerExpression( "equal-unsignedinteger16-double", new PrimitiveCreator<Equal<uint_16,double> >() );
    factory->registerExpression( "equal-unsignedinteger16-float", new PrimitiveCreator<Equal<uint_16,float> >() );
    factory->registerExpression( "equal-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<Equal<uint_16,uint_64> >() );
    factory->registerExpression( "equal-unsignedinteger16-integer64", new PrimitiveCreator<Equal<uint_16,int_64> >() );
    factory->registerExpression( "equal-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<Equal<uint_16,uint_32> >() );
    factory->registerExpression( "equal-unsignedinteger16-integer32", new PrimitiveCreator<Equal<uint_16,int_32> >() );
    factory->registerExpression( "equal-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<Equal<uint_16,uint_16> >() );
    factory->registerExpression( "equal-unsignedinteger16-integer16", new PrimitiveCreator<Equal<uint_16,int_16> >() );
    factory->registerExpression( "equal-integer16-double", new PrimitiveCreator<Equal<int_16,double> >() );
    factory->registerExpression( "equal-integer16-float", new PrimitiveCreator<Equal<int_16,float> >() );
    factory->registerExpression( "equal-integer16-unsignedinteger64", new PrimitiveCreator<Equal<int_16,uint_64> >() );
    factory->registerExpression( "equal-integer16-integer64", new PrimitiveCreator<Equal<int_16,int_64> >() );
    factory->registerExpression( "equal-integer16-unsignedinteger32", new PrimitiveCreator<Equal<int_16,uint_32> >() );
    factory->registerExpression( "equal-integer16-integer32", new PrimitiveCreator<Equal<int_16,int_32> >() );
    factory->registerExpression( "equal-integer16-unsignedinteger16", new PrimitiveCreator<Equal<int_16,uint_16> >() );
    factory->registerExpression( "equal-integer16-integer16", new PrimitiveCreator<Equal<int_16,int_16> >() );
    factory->registerExpression( "notequal-double-double", new PrimitiveCreator<NotEqual<double,double> >() );
    factory->registerExpression( "notequal-double-float", new PrimitiveCreator<NotEqual<double,float> >() );
    factory->registerExpression( "notequal-double-unsignedinteger64", new PrimitiveCreator<NotEqual<double,uint_64> >() );
    factory->registerExpression( "notequal-double-integer64", new PrimitiveCreator<NotEqual<double,int_64> >() );
    factory->registerExpression( "notequal-double-unsignedinteger32", new PrimitiveCreator<NotEqual<double,uint_32> >() );
    factory->registerExpression( "notequal-double-integer32", new PrimitiveCreator<NotEqual<double,int_32> >() );
    factory->registerExpression( "notequal-double-unsignedinteger16", new PrimitiveCreator<NotEqual<double,uint_16> >() );
    factory->registerExpression( "notequal-double-integer16", new PrimitiveCreator<NotEqual<double,int_16> >() );
    factory->registerExpression( "notequal-float-double", new PrimitiveCreator<NotEqual<float,double> >() );
    factory->registerExpression( "notequal-float-float", new PrimitiveCreator<NotEqual<float,float> >() );
    factory->registerExpression( "notequal-float-unsignedinteger64", new PrimitiveCreator<NotEqual<float,uint_64> >() );
    factory->registerExpression( "notequal-float-integer64", new PrimitiveCreator<NotEqual<float,int_64> >() );
    factory->registerExpression( "notequal-float-unsignedinteger32", new PrimitiveCreator<NotEqual<float,uint_32> >() );
    factory->registerExpression( "notequal-float-integer32", new PrimitiveCreator<NotEqual<float,int_32> >() );
    factory->registerExpression( "notequal-float-unsignedinteger16", new PrimitiveCreator<NotEqual<float,uint_16> >() );
    factory->registerExpression( "notequal-float-integer16", new PrimitiveCreator<NotEqual<float,int_16> >() );
    factory->registerExpression( "notequal-unsignedinteger64-double", new PrimitiveCreator<NotEqual<uint_64,double> >() );
    factory->registerExpression( "notequal-unsignedinteger64-float", new PrimitiveCreator<NotEqual<uint_64,float> >() );
    factory->registerExpression( "notequal-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<NotEqual<uint_64,uint_64> >() );
    factory->registerExpression( "notequal-unsignedinteger64-integer64", new PrimitiveCreator<NotEqual<uint_64,int_64> >() );
    factory->registerExpression( "notequal-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<NotEqual<uint_64,uint_32> >() );
    factory->registerExpression( "notequal-unsignedinteger64-integer32", new PrimitiveCreator<NotEqual<uint_64,int_32> >() );
    factory->registerExpression( "notequal-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<NotEqual<uint_64,uint_16> >() );
    factory->registerExpression( "notequal-unsignedinteger64-integer16", new PrimitiveCreator<NotEqual<uint_64,int_16> >() );
    factory->registerExpression( "notequal-integer64-double", new PrimitiveCreator<NotEqual<int_64,double> >() );
    factory->registerExpression( "notequal-integer64-float", new PrimitiveCreator<NotEqual<int_64,float> >() );
    factory->registerExpression( "notequal-integer64-unsignedinteger64", new PrimitiveCreator<NotEqual<int_64,uint_64> >() );
    factory->registerExpression( "notequal-integer64-integer64", new PrimitiveCreator<NotEqual<int_64,int_64> >() );
    factory->registerExpression( "notequal-integer64-unsignedinteger32", new PrimitiveCreator<NotEqual<int_64,uint_32> >() );
    factory->registerExpression( "notequal-integer64-integer32", new PrimitiveCreator<NotEqual<int_64,int_32> >() );
    factory->registerExpression( "notequal-integer64-unsignedinteger16", new PrimitiveCreator<NotEqual<int_64,uint_16> >() );
    factory->registerExpression( "notequal-integer64-integer16", new PrimitiveCreator<NotEqual<int_64,int_16> >() );
    factory->registerExpression( "notequal-unsignedinteger32-double", new PrimitiveCreator<NotEqual<uint_32,double> >() );
    factory->registerExpression( "notequal-unsignedinteger32-float", new PrimitiveCreator<NotEqual<uint_32,float> >() );
    factory->registerExpression( "notequal-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<NotEqual<uint_32,uint_64> >() );
    factory->registerExpression( "notequal-unsignedinteger32-integer64", new PrimitiveCreator<NotEqual<uint_32,int_64> >() );
    factory->registerExpression( "notequal-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<NotEqual<uint_32,uint_32> >() );
    factory->registerExpression( "notequal-unsignedinteger32-integer32", new PrimitiveCreator<NotEqual<uint_32,int_32> >() );
    factory->registerExpression( "notequal-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<NotEqual<uint_32,uint_16> >() );
    factory->registerExpression( "notequal-unsignedinteger32-integer16", new PrimitiveCreator<NotEqual<uint_32,int_16> >() );
    factory->registerExpression( "notequal-integer32-double", new PrimitiveCreator<NotEqual<int_32,double> >() );
    factory->registerExpression( "notequal-integer32-float", new PrimitiveCreator<NotEqual<int_32,float> >() );
    factory->registerExpression( "notequal-integer32-unsignedinteger64", new PrimitiveCreator<NotEqual<int_32,uint_64> >() );
    factory->registerExpression( "notequal-integer32-integer64", new PrimitiveCreator<NotEqual<int_32,int_64> >() );
    factory->registerExpression( "notequal-integer32-unsignedinteger32", new PrimitiveCreator<NotEqual<int_32,uint_32> >() );
    factory->registerExpression( "notequal-integer32-integer32", new PrimitiveCreator<NotEqual<int_32,int_32> >() );
    factory->registerExpression( "notequal-integer32-unsignedinteger16", new PrimitiveCreator<NotEqual<int_32,uint_16> >() );
    factory->registerExpression( "notequal-integer32-integer16", new PrimitiveCreator<NotEqual<int_32,int_16> >() );
    factory->registerExpression( "notequal-unsignedinteger16-double", new PrimitiveCreator<NotEqual<uint_16,double> >() );
    factory->registerExpression( "notequal-unsignedinteger16-float", new PrimitiveCreator<NotEqual<uint_16,float> >() );
    factory->registerExpression( "notequal-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<NotEqual<uint_16,uint_64> >() );
    factory->registerExpression( "notequal-unsignedinteger16-integer64", new PrimitiveCreator<NotEqual<uint_16,int_64> >() );
    factory->registerExpression( "notequal-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<NotEqual<uint_16,uint_32> >() );
    factory->registerExpression( "notequal-unsignedinteger16-integer32", new PrimitiveCreator<NotEqual<uint_16,int_32> >() );
    factory->registerExpression( "notequal-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<NotEqual<uint_16,uint_16> >() );
    factory->registerExpression( "notequal-unsignedinteger16-integer16", new PrimitiveCreator<NotEqual<uint_16,int_16> >() );
    factory->registerExpression( "notequal-integer16-double", new PrimitiveCreator<NotEqual<int_16,double> >() );
    factory->registerExpression( "notequal-integer16-float", new PrimitiveCreator<NotEqual<int_16,float> >() );
    factory->registerExpression( "notequal-integer16-unsignedinteger64", new PrimitiveCreator<NotEqual<int_16,uint_64> >() );
    factory->registerExpression( "notequal-integer16-integer64", new PrimitiveCreator<NotEqual<int_16,int_64> >() );
    factory->registerExpression( "notequal-integer16-unsignedinteger32", new PrimitiveCreator<NotEqual<int_16,uint_32> >() );
    factory->registerExpression( "notequal-integer16-integer32", new PrimitiveCreator<NotEqual<int_16,int_32> >() );
    factory->registerExpression( "notequal-integer16-unsignedinteger16", new PrimitiveCreator<NotEqual<int_16,uint_16> >() );
    factory->registerExpression( "notequal-integer16-integer16", new PrimitiveCreator<NotEqual<int_16,int_16> >() );
    factory->registerExpression( "lessthan-double-double", new PrimitiveCreator<LessThan<double,double> >() );
    factory->registerExpression( "lessthan-double-float", new PrimitiveCreator<LessThan<double,float> >() );
    factory->registerExpression( "lessthan-double-unsignedinteger64", new PrimitiveCreator<LessThan<double,uint_64> >() );
    factory->registerExpression( "lessthan-double-integer64", new PrimitiveCreator<LessThan<double,int_64> >() );
    factory->registerExpression( "lessthan-double-unsignedinteger32", new PrimitiveCreator<LessThan<double,uint_32> >() );
    factory->registerExpression( "lessthan-double-integer32", new PrimitiveCreator<LessThan<double,int_32> >() );
    factory->registerExpression( "lessthan-double-unsignedinteger16", new PrimitiveCreator<LessThan<double,uint_16> >() );
    factory->registerExpression( "lessthan-double-integer16", new PrimitiveCreator<LessThan<double,int_16> >() );
    factory->registerExpression( "lessthan-float-double", new PrimitiveCreator<LessThan<float,double> >() );
    factory->registerExpression( "lessthan-float-float", new PrimitiveCreator<LessThan<float,float> >() );
    factory->registerExpression( "lessthan-float-unsignedinteger64", new PrimitiveCreator<LessThan<float,uint_64> >() );
    factory->registerExpression( "lessthan-float-integer64", new PrimitiveCreator<LessThan<float,int_64> >() );
    factory->registerExpression( "lessthan-float-unsignedinteger32", new PrimitiveCreator<LessThan<float,uint_32> >() );
    factory->registerExpression( "lessthan-float-integer32", new PrimitiveCreator<LessThan<float,int_32> >() );
    factory->registerExpression( "lessthan-float-unsignedinteger16", new PrimitiveCreator<LessThan<float,uint_16> >() );
    factory->registerExpression( "lessthan-float-integer16", new PrimitiveCreator<LessThan<float,int_16> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-double", new PrimitiveCreator<LessThan<uint_64,double> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-float", new PrimitiveCreator<LessThan<uint_64,float> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<LessThan<uint_64,uint_64> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-integer64", new PrimitiveCreator<LessThan<uint_64,int_64> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<LessThan<uint_64,uint_32> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-integer32", new PrimitiveCreator<LessThan<uint_64,int_32> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<LessThan<uint_64,uint_16> >() );
    factory->registerExpression( "lessthan-unsignedinteger64-integer16", new PrimitiveCreator<LessThan<uint_64,int_16> >() );
    factory->registerExpression( "lessthan-integer64-double", new PrimitiveCreator<LessThan<int_64,double> >() );
    factory->registerExpression( "lessthan-integer64-float", new PrimitiveCreator<LessThan<int_64,float> >() );
    factory->registerExpression( "lessthan-integer64-unsignedinteger64", new PrimitiveCreator<LessThan<int_64,uint_64> >() );
    factory->registerExpression( "lessthan-integer64-integer64", new PrimitiveCreator<LessThan<int_64,int_64> >() );
    factory->registerExpression( "lessthan-integer64-unsignedinteger32", new PrimitiveCreator<LessThan<int_64,uint_32> >() );
    factory->registerExpression( "lessthan-integer64-integer32", new PrimitiveCreator<LessThan<int_64,int_32> >() );
    factory->registerExpression( "lessthan-integer64-unsignedinteger16", new PrimitiveCreator<LessThan<int_64,uint_16> >() );
    factory->registerExpression( "lessthan-integer64-integer16", new PrimitiveCreator<LessThan<int_64,int_16> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-double", new PrimitiveCreator<LessThan<uint_32,double> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-float", new PrimitiveCreator<LessThan<uint_32,float> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<LessThan<uint_32,uint_64> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-integer64", new PrimitiveCreator<LessThan<uint_32,int_64> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<LessThan<uint_32,uint_32> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-integer32", new PrimitiveCreator<LessThan<uint_32,int_32> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<LessThan<uint_32,uint_16> >() );
    factory->registerExpression( "lessthan-unsignedinteger32-integer16", new PrimitiveCreator<LessThan<uint_32,int_16> >() );
    factory->registerExpression( "lessthan-integer32-double", new PrimitiveCreator<LessThan<int_32,double> >() );
    factory->registerExpression( "lessthan-integer32-float", new PrimitiveCreator<LessThan<int_32,float> >() );
    factory->registerExpression( "lessthan-integer32-unsignedinteger64", new PrimitiveCreator<LessThan<int_32,uint_64> >() );
    factory->registerExpression( "lessthan-integer32-integer64", new PrimitiveCreator<LessThan<int_32,int_64> >() );
    factory->registerExpression( "lessthan-integer32-unsignedinteger32", new PrimitiveCreator<LessThan<int_32,uint_32> >() );
    factory->registerExpression( "lessthan-integer32-integer32", new PrimitiveCreator<LessThan<int_32,int_32> >() );
    factory->registerExpression( "lessthan-integer32-unsignedinteger16", new PrimitiveCreator<LessThan<int_32,uint_16> >() );
    factory->registerExpression( "lessthan-integer32-integer16", new PrimitiveCreator<LessThan<int_32,int_16> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-double", new PrimitiveCreator<LessThan<uint_16,double> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-float", new PrimitiveCreator<LessThan<uint_16,float> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<LessThan<uint_16,uint_64> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-integer64", new PrimitiveCreator<LessThan<uint_16,int_64> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<LessThan<uint_16,uint_32> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-integer32", new PrimitiveCreator<LessThan<uint_16,int_32> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<LessThan<uint_16,uint_16> >() );
    factory->registerExpression( "lessthan-unsignedinteger16-integer16", new PrimitiveCreator<LessThan<uint_16,int_16> >() );
    factory->registerExpression( "lessthan-integer16-double", new PrimitiveCreator<LessThan<int_16,double> >() );
    factory->registerExpression( "lessthan-integer16-float", new PrimitiveCreator<LessThan<int_16,float> >() );
    factory->registerExpression( "lessthan-integer16-unsignedinteger64", new PrimitiveCreator<LessThan<int_16,uint_64> >() );
    factory->registerExpression( "lessthan-integer16-integer64", new PrimitiveCreator<LessThan<int_16,int_64> >() );
    factory->registerExpression( "lessthan-integer16-unsignedinteger32", new PrimitiveCreator<LessThan<int_16,uint_32> >() );
    factory->registerExpression( "lessthan-integer16-integer32", new PrimitiveCreator<LessThan<int_16,int_32> >() );
    factory->registerExpression( "lessthan-integer16-unsignedinteger16", new PrimitiveCreator<LessThan<int_16,uint_16> >() );
    factory->registerExpression( "lessthan-integer16-integer16", new PrimitiveCreator<LessThan<int_16,int_16> >() );
    factory->registerExpression( "greaterthan-double-double", new PrimitiveCreator<GreaterThan<double,double> >() );
    factory->registerExpression( "greaterthan-double-float", new PrimitiveCreator<GreaterThan<double,float> >() );
    factory->registerExpression( "greaterthan-double-unsignedinteger64", new PrimitiveCreator<GreaterThan<double,uint_64> >() );
    factory->registerExpression( "greaterthan-double-integer64", new PrimitiveCreator<GreaterThan<double,int_64> >() );
    factory->registerExpression( "greaterthan-double-unsignedinteger32", new PrimitiveCreator<GreaterThan<double,uint_32> >() );
    factory->registerExpression( "greaterthan-double-integer32", new PrimitiveCreator<GreaterThan<double,int_32> >() );
    factory->registerExpression( "greaterthan-double-unsignedinteger16", new PrimitiveCreator<GreaterThan<double,uint_16> >() );
    factory->registerExpression( "greaterthan-double-integer16", new PrimitiveCreator<GreaterThan<double,int_16> >() );
    factory->registerExpression( "greaterthan-float-double", new PrimitiveCreator<GreaterThan<float,double> >() );
    factory->registerExpression( "greaterthan-float-float", new PrimitiveCreator<GreaterThan<float,float> >() );
    factory->registerExpression( "greaterthan-float-unsignedinteger64", new PrimitiveCreator<GreaterThan<float,uint_64> >() );
    factory->registerExpression( "greaterthan-float-integer64", new PrimitiveCreator<GreaterThan<float,int_64> >() );
    factory->registerExpression( "greaterthan-float-unsignedinteger32", new PrimitiveCreator<GreaterThan<float,uint_32> >() );
    factory->registerExpression( "greaterthan-float-integer32", new PrimitiveCreator<GreaterThan<float,int_32> >() );
    factory->registerExpression( "greaterthan-float-unsignedinteger16", new PrimitiveCreator<GreaterThan<float,uint_16> >() );
    factory->registerExpression( "greaterthan-float-integer16", new PrimitiveCreator<GreaterThan<float,int_16> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-double", new PrimitiveCreator<GreaterThan<uint_64,double> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-float", new PrimitiveCreator<GreaterThan<uint_64,float> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<GreaterThan<uint_64,uint_64> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-integer64", new PrimitiveCreator<GreaterThan<uint_64,int_64> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<GreaterThan<uint_64,uint_32> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-integer32", new PrimitiveCreator<GreaterThan<uint_64,int_32> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<GreaterThan<uint_64,uint_16> >() );
    factory->registerExpression( "greaterthan-unsignedinteger64-integer16", new PrimitiveCreator<GreaterThan<uint_64,int_16> >() );
    factory->registerExpression( "greaterthan-integer64-double", new PrimitiveCreator<GreaterThan<int_64,double> >() );
    factory->registerExpression( "greaterthan-integer64-float", new PrimitiveCreator<GreaterThan<int_64,float> >() );
    factory->registerExpression( "greaterthan-integer64-unsignedinteger64", new PrimitiveCreator<GreaterThan<int_64,uint_64> >() );
    factory->registerExpression( "greaterthan-integer64-integer64", new PrimitiveCreator<GreaterThan<int_64,int_64> >() );
    factory->registerExpression( "greaterthan-integer64-unsignedinteger32", new PrimitiveCreator<GreaterThan<int_64,uint_32> >() );
    factory->registerExpression( "greaterthan-integer64-integer32", new PrimitiveCreator<GreaterThan<int_64,int_32> >() );
    factory->registerExpression( "greaterthan-integer64-unsignedinteger16", new PrimitiveCreator<GreaterThan<int_64,uint_16> >() );
    factory->registerExpression( "greaterthan-integer64-integer16", new PrimitiveCreator<GreaterThan<int_64,int_16> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-double", new PrimitiveCreator<GreaterThan<uint_32,double> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-float", new PrimitiveCreator<GreaterThan<uint_32,float> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<GreaterThan<uint_32,uint_64> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-integer64", new PrimitiveCreator<GreaterThan<uint_32,int_64> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<GreaterThan<uint_32,uint_32> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-integer32", new PrimitiveCreator<GreaterThan<uint_32,int_32> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<GreaterThan<uint_32,uint_16> >() );
    factory->registerExpression( "greaterthan-unsignedinteger32-integer16", new PrimitiveCreator<GreaterThan<uint_32,int_16> >() );
    factory->registerExpression( "greaterthan-integer32-double", new PrimitiveCreator<GreaterThan<int_32,double> >() );
    factory->registerExpression( "greaterthan-integer32-float", new PrimitiveCreator<GreaterThan<int_32,float> >() );
    factory->registerExpression( "greaterthan-integer32-unsignedinteger64", new PrimitiveCreator<GreaterThan<int_32,uint_64> >() );
    factory->registerExpression( "greaterthan-integer32-integer64", new PrimitiveCreator<GreaterThan<int_32,int_64> >() );
    factory->registerExpression( "greaterthan-integer32-unsignedinteger32", new PrimitiveCreator<GreaterThan<int_32,uint_32> >() );
    factory->registerExpression( "greaterthan-integer32-integer32", new PrimitiveCreator<GreaterThan<int_32,int_32> >() );
    factory->registerExpression( "greaterthan-integer32-unsignedinteger16", new PrimitiveCreator<GreaterThan<int_32,uint_16> >() );
    factory->registerExpression( "greaterthan-integer32-integer16", new PrimitiveCreator<GreaterThan<int_32,int_16> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-double", new PrimitiveCreator<GreaterThan<uint_16,double> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-float", new PrimitiveCreator<GreaterThan<uint_16,float> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<GreaterThan<uint_16,uint_64> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-integer64", new PrimitiveCreator<GreaterThan<uint_16,int_64> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<GreaterThan<uint_16,uint_32> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-integer32", new PrimitiveCreator<GreaterThan<uint_16,int_32> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<GreaterThan<uint_16,uint_16> >() );
    factory->registerExpression( "greaterthan-unsignedinteger16-integer16", new PrimitiveCreator<GreaterThan<uint_16,int_16> >() );
    factory->registerExpression( "greaterthan-integer16-double", new PrimitiveCreator<GreaterThan<int_16,double> >() );
    factory->registerExpression( "greaterthan-integer16-float", new PrimitiveCreator<GreaterThan<int_16,float> >() );
    factory->registerExpression( "greaterthan-integer16-unsignedinteger64", new PrimitiveCreator<GreaterThan<int_16,uint_64> >() );
    factory->registerExpression( "greaterthan-integer16-integer64", new PrimitiveCreator<GreaterThan<int_16,int_64> >() );
    factory->registerExpression( "greaterthan-integer16-unsignedinteger32", new PrimitiveCreator<GreaterThan<int_16,uint_32> >() );
    factory->registerExpression( "greaterthan-integer16-integer32", new PrimitiveCreator<GreaterThan<int_16,int_32> >() );
    factory->registerExpression( "greaterthan-integer16-unsignedinteger16", new PrimitiveCreator<GreaterThan<int_16,uint_16> >() );
    factory->registerExpression( "greaterthan-integer16-integer16", new PrimitiveCreator<GreaterThan<int_16,int_16> >() );
    factory->registerExpression( "lessthanequal-double-double", new PrimitiveCreator<LessThanEqual<double,double> >() );
    factory->registerExpression( "lessthanequal-double-float", new PrimitiveCreator<LessThanEqual<double,float> >() );
    factory->registerExpression( "lessthanequal-double-unsignedinteger64", new PrimitiveCreator<LessThanEqual<double,uint_64> >() );
    factory->registerExpression( "lessthanequal-double-integer64", new PrimitiveCreator<LessThanEqual<double,int_64> >() );
    factory->registerExpression( "lessthanequal-double-unsignedinteger32", new PrimitiveCreator<LessThanEqual<double,uint_32> >() );
    factory->registerExpression( "lessthanequal-double-integer32", new PrimitiveCreator<LessThanEqual<double,int_32> >() );
    factory->registerExpression( "lessthanequal-double-unsignedinteger16", new PrimitiveCreator<LessThanEqual<double,uint_16> >() );
    factory->registerExpression( "lessthanequal-double-integer16", new PrimitiveCreator<LessThanEqual<double,int_16> >() );
    factory->registerExpression( "lessthanequal-float-double", new PrimitiveCreator<LessThanEqual<float,double> >() );
    factory->registerExpression( "lessthanequal-float-float", new PrimitiveCreator<LessThanEqual<float,float> >() );
    factory->registerExpression( "lessthanequal-float-unsignedinteger64", new PrimitiveCreator<LessThanEqual<float,uint_64> >() );
    factory->registerExpression( "lessthanequal-float-integer64", new PrimitiveCreator<LessThanEqual<float,int_64> >() );
    factory->registerExpression( "lessthanequal-float-unsignedinteger32", new PrimitiveCreator<LessThanEqual<float,uint_32> >() );
    factory->registerExpression( "lessthanequal-float-integer32", new PrimitiveCreator<LessThanEqual<float,int_32> >() );
    factory->registerExpression( "lessthanequal-float-unsignedinteger16", new PrimitiveCreator<LessThanEqual<float,uint_16> >() );
    factory->registerExpression( "lessthanequal-float-integer16", new PrimitiveCreator<LessThanEqual<float,int_16> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-double", new PrimitiveCreator<LessThanEqual<uint_64,double> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-float", new PrimitiveCreator<LessThanEqual<uint_64,float> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<LessThanEqual<uint_64,uint_64> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-integer64", new PrimitiveCreator<LessThanEqual<uint_64,int_64> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<LessThanEqual<uint_64,uint_32> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-integer32", new PrimitiveCreator<LessThanEqual<uint_64,int_32> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<LessThanEqual<uint_64,uint_16> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger64-integer16", new PrimitiveCreator<LessThanEqual<uint_64,int_16> >() );
    factory->registerExpression( "lessthanequal-integer64-double", new PrimitiveCreator<LessThanEqual<int_64,double> >() );
    factory->registerExpression( "lessthanequal-integer64-float", new PrimitiveCreator<LessThanEqual<int_64,float> >() );
    factory->registerExpression( "lessthanequal-integer64-unsignedinteger64", new PrimitiveCreator<LessThanEqual<int_64,uint_64> >() );
    factory->registerExpression( "lessthanequal-integer64-integer64", new PrimitiveCreator<LessThanEqual<int_64,int_64> >() );
    factory->registerExpression( "lessthanequal-integer64-unsignedinteger32", new PrimitiveCreator<LessThanEqual<int_64,uint_32> >() );
    factory->registerExpression( "lessthanequal-integer64-integer32", new PrimitiveCreator<LessThanEqual<int_64,int_32> >() );
    factory->registerExpression( "lessthanequal-integer64-unsignedinteger16", new PrimitiveCreator<LessThanEqual<int_64,uint_16> >() );
    factory->registerExpression( "lessthanequal-integer64-integer16", new PrimitiveCreator<LessThanEqual<int_64,int_16> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-double", new PrimitiveCreator<LessThanEqual<uint_32,double> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-float", new PrimitiveCreator<LessThanEqual<uint_32,float> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<LessThanEqual<uint_32,uint_64> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-integer64", new PrimitiveCreator<LessThanEqual<uint_32,int_64> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<LessThanEqual<uint_32,uint_32> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-integer32", new PrimitiveCreator<LessThanEqual<uint_32,int_32> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<LessThanEqual<uint_32,uint_16> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger32-integer16", new PrimitiveCreator<LessThanEqual<uint_32,int_16> >() );
    factory->registerExpression( "lessthanequal-integer32-double", new PrimitiveCreator<LessThanEqual<int_32,double> >() );
    factory->registerExpression( "lessthanequal-integer32-float", new PrimitiveCreator<LessThanEqual<int_32,float> >() );
    factory->registerExpression( "lessthanequal-integer32-unsignedinteger64", new PrimitiveCreator<LessThanEqual<int_32,uint_64> >() );
    factory->registerExpression( "lessthanequal-integer32-integer64", new PrimitiveCreator<LessThanEqual<int_32,int_64> >() );
    factory->registerExpression( "lessthanequal-integer32-unsignedinteger32", new PrimitiveCreator<LessThanEqual<int_32,uint_32> >() );
    factory->registerExpression( "lessthanequal-integer32-integer32", new PrimitiveCreator<LessThanEqual<int_32,int_32> >() );
    factory->registerExpression( "lessthanequal-integer32-unsignedinteger16", new PrimitiveCreator<LessThanEqual<int_32,uint_16> >() );
    factory->registerExpression( "lessthanequal-integer32-integer16", new PrimitiveCreator<LessThanEqual<int_32,int_16> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-double", new PrimitiveCreator<LessThanEqual<uint_16,double> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-float", new PrimitiveCreator<LessThanEqual<uint_16,float> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<LessThanEqual<uint_16,uint_64> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-integer64", new PrimitiveCreator<LessThanEqual<uint_16,int_64> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<LessThanEqual<uint_16,uint_32> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-integer32", new PrimitiveCreator<LessThanEqual<uint_16,int_32> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<LessThanEqual<uint_16,uint_16> >() );
    factory->registerExpression( "lessthanequal-unsignedinteger16-integer16", new PrimitiveCreator<LessThanEqual<uint_16,int_16> >() );
    factory->registerExpression( "lessthanequal-integer16-double", new PrimitiveCreator<LessThanEqual<int_16,double> >() );
    factory->registerExpression( "lessthanequal-integer16-float", new PrimitiveCreator<LessThanEqual<int_16,float> >() );
    factory->registerExpression( "lessthanequal-integer16-unsignedinteger64", new PrimitiveCreator<LessThanEqual<int_16,uint_64> >() );
    factory->registerExpression( "lessthanequal-integer16-integer64", new PrimitiveCreator<LessThanEqual<int_16,int_64> >() );
    factory->registerExpression( "lessthanequal-integer16-unsignedinteger32", new PrimitiveCreator<LessThanEqual<int_16,uint_32> >() );
    factory->registerExpression( "lessthanequal-integer16-integer32", new PrimitiveCreator<LessThanEqual<int_16,int_32> >() );
    factory->registerExpression( "lessthanequal-integer16-unsignedinteger16", new PrimitiveCreator<LessThanEqual<int_16,uint_16> >() );
    factory->registerExpression( "lessthanequal-integer16-integer16", new PrimitiveCreator<LessThanEqual<int_16,int_16> >() );
    factory->registerExpression( "greaterthanequal-double-double", new PrimitiveCreator<GreaterThanEqual<double,double> >() );
    factory->registerExpression( "greaterthanequal-double-float", new PrimitiveCreator<GreaterThanEqual<double,float> >() );
    factory->registerExpression( "greaterthanequal-double-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<double,uint_64> >() );
    factory->registerExpression( "greaterthanequal-double-integer64", new PrimitiveCreator<GreaterThanEqual<double,int_64> >() );
    factory->registerExpression( "greaterthanequal-double-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<double,uint_32> >() );
    factory->registerExpression( "greaterthanequal-double-integer32", new PrimitiveCreator<GreaterThanEqual<double,int_32> >() );
    factory->registerExpression( "greaterthanequal-double-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<double,uint_16> >() );
    factory->registerExpression( "greaterthanequal-double-integer16", new PrimitiveCreator<GreaterThanEqual<double,int_16> >() );
    factory->registerExpression( "greaterthanequal-float-double", new PrimitiveCreator<GreaterThanEqual<float,double> >() );
    factory->registerExpression( "greaterthanequal-float-float", new PrimitiveCreator<GreaterThanEqual<float,float> >() );
    factory->registerExpression( "greaterthanequal-float-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<float,uint_64> >() );
    factory->registerExpression( "greaterthanequal-float-integer64", new PrimitiveCreator<GreaterThanEqual<float,int_64> >() );
    factory->registerExpression( "greaterthanequal-float-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<float,uint_32> >() );
    factory->registerExpression( "greaterthanequal-float-integer32", new PrimitiveCreator<GreaterThanEqual<float,int_32> >() );
    factory->registerExpression( "greaterthanequal-float-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<float,uint_16> >() );
    factory->registerExpression( "greaterthanequal-float-integer16", new PrimitiveCreator<GreaterThanEqual<float,int_16> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-double", new PrimitiveCreator<GreaterThanEqual<uint_64,double> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-float", new PrimitiveCreator<GreaterThanEqual<uint_64,float> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<uint_64,uint_64> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-integer64", new PrimitiveCreator<GreaterThanEqual<uint_64,int_64> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<uint_64,uint_32> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-integer32", new PrimitiveCreator<GreaterThanEqual<uint_64,int_32> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<uint_64,uint_16> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger64-integer16", new PrimitiveCreator<GreaterThanEqual<uint_64,int_16> >() );
    factory->registerExpression( "greaterthanequal-integer64-double", new PrimitiveCreator<GreaterThanEqual<int_64,double> >() );
    factory->registerExpression( "greaterthanequal-integer64-float", new PrimitiveCreator<GreaterThanEqual<int_64,float> >() );
    factory->registerExpression( "greaterthanequal-integer64-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<int_64,uint_64> >() );
    factory->registerExpression( "greaterthanequal-integer64-integer64", new PrimitiveCreator<GreaterThanEqual<int_64,int_64> >() );
    factory->registerExpression( "greaterthanequal-integer64-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<int_64,uint_32> >() );
    factory->registerExpression( "greaterthanequal-integer64-integer32", new PrimitiveCreator<GreaterThanEqual<int_64,int_32> >() );
    factory->registerExpression( "greaterthanequal-integer64-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<int_64,uint_16> >() );
    factory->registerExpression( "greaterthanequal-integer64-integer16", new PrimitiveCreator<GreaterThanEqual<int_64,int_16> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-double", new PrimitiveCreator<GreaterThanEqual<uint_32,double> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-float", new PrimitiveCreator<GreaterThanEqual<uint_32,float> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<uint_32,uint_64> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-integer64", new PrimitiveCreator<GreaterThanEqual<uint_32,int_64> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<uint_32,uint_32> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-integer32", new PrimitiveCreator<GreaterThanEqual<uint_32,int_32> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<uint_32,uint_16> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger32-integer16", new PrimitiveCreator<GreaterThanEqual<uint_32,int_16> >() );
    factory->registerExpression( "greaterthanequal-integer32-double", new PrimitiveCreator<GreaterThanEqual<int_32,double> >() );
    factory->registerExpression( "greaterthanequal-integer32-float", new PrimitiveCreator<GreaterThanEqual<int_32,float> >() );
    factory->registerExpression( "greaterthanequal-integer32-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<int_32,uint_64> >() );
    factory->registerExpression( "greaterthanequal-integer32-integer64", new PrimitiveCreator<GreaterThanEqual<int_32,int_64> >() );
    factory->registerExpression( "greaterthanequal-integer32-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<int_32,uint_32> >() );
    factory->registerExpression( "greaterthanequal-integer32-integer32", new PrimitiveCreator<GreaterThanEqual<int_32,int_32> >() );
    factory->registerExpression( "greaterthanequal-integer32-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<int_32,uint_16> >() );
    factory->registerExpression( "greaterthanequal-integer32-integer16", new PrimitiveCreator<GreaterThanEqual<int_32,int_16> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-double", new PrimitiveCreator<GreaterThanEqual<uint_16,double> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-float", new PrimitiveCreator<GreaterThanEqual<uint_16,float> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<uint_16,uint_64> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-integer64", new PrimitiveCreator<GreaterThanEqual<uint_16,int_64> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<uint_16,uint_32> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-integer32", new PrimitiveCreator<GreaterThanEqual<uint_16,int_32> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<uint_16,uint_16> >() );
    factory->registerExpression( "greaterthanequal-unsignedinteger16-integer16", new PrimitiveCreator<GreaterThanEqual<uint_16,int_16> >() );
    factory->registerExpression( "greaterthanequal-integer16-double", new PrimitiveCreator<GreaterThanEqual<int_16,double> >() );
    factory->registerExpression( "greaterthanequal-integer16-float", new PrimitiveCreator<GreaterThanEqual<int_16,float> >() );
    factory->registerExpression( "greaterthanequal-integer16-unsignedinteger64", new PrimitiveCreator<GreaterThanEqual<int_16,uint_64> >() );
    factory->registerExpression( "greaterthanequal-integer16-integer64", new PrimitiveCreator<GreaterThanEqual<int_16,int_64> >() );
    factory->registerExpression( "greaterthanequal-integer16-unsignedinteger32", new PrimitiveCreator<GreaterThanEqual<int_16,uint_32> >() );
    factory->registerExpression( "greaterthanequal-integer16-integer32", new PrimitiveCreator<GreaterThanEqual<int_16,int_32> >() );
    factory->registerExpression( "greaterthanequal-integer16-unsignedinteger16", new PrimitiveCreator<GreaterThanEqual<int_16,uint_16> >() );
    factory->registerExpression( "greaterthanequal-integer16-integer16", new PrimitiveCreator<GreaterThanEqual<int_16,int_16> >() );
    factory->registerExpression( "equal-boolean-boolean", new PrimitiveCreator<Equal<bool,bool> >() );
    factory->registerExpression( "notequal-boolean-boolean", new PrimitiveCreator<NotEqual<bool,bool> >() );
    factory->registerExpression( "lessthan-boolean-boolean", new PrimitiveCreator<LessThan<bool,bool> >() );
    factory->registerExpression( "greaterthan-boolean-boolean", new PrimitiveCreator<GreaterThan<bool,bool> >() );
    factory->registerExpression( "lessthanequal-boolean-boolean", new PrimitiveCreator<LessThanEqual<bool,bool> >() );
    factory->registerExpression( "greaterthanequal-boolean-boolean", new PrimitiveCreator<GreaterThanEqual<bool,bool> >() );
    factory->registerExpression( "equal-string-string", new PrimitiveCreator<Equal<std::string,std::string> >() );
    factory->registerExpression( "notequal-string-string", new PrimitiveCreator<NotEqual<std::string,std::string> >() );
    factory->registerExpression( "lessthan-string-string", new PrimitiveCreator<LessThan<std::string,std::string> >() );
    factory->registerExpression( "greaterthan-string-string", new PrimitiveCreator<GreaterThan<std::string,std::string> >() );
    factory->registerExpression( "lessthanequal-string-string", new PrimitiveCreator<LessThanEqual<std::string,std::string> >() );
    factory->registerExpression( "greaterthanequal-string-string", new PrimitiveCreator<GreaterThanEqual<std::string,std::string> >() );
    RULEENGINE_STACK_TRACE_EXIT
}
};
/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
