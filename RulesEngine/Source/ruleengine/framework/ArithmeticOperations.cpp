// ArithmeticOperations.cpp
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ExpressionCreator.h>
/*********************************************************************
#    File        :  ArithmeticOperations.cpp
#    Abstract    :  Implementation of ArithmeticOperations.
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
#    2  Kishore   25-May-2007  registerArithmeticOperations() was 
#                              taking map as its parameter and filling it.
#                              Used ExpressionFactory::register instead
#
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/

namespace ruleengine
{

//////////////////////////////////////////////////////////////////////////
//
//  This funtion registers ArithmeticOperations in the ExpressionFactory.
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
void registerArithmeticOperations()
{
    RULEENGINE_STACK_TRACE_ENTRY
    ExpressionFactory* factory = &ExpressionFactory::getInstance();
    factory->registerExpression( "add-double-double", new PrimitiveCreator<Add<double,double,double> >() );
    factory->registerExpression( "add-double-float", new PrimitiveCreator<Add<double,float,double> >() );
    factory->registerExpression( "add-double-unsignedinteger64", new PrimitiveCreator<Add<double,uint_64,double> >() );
    factory->registerExpression( "add-double-integer64", new PrimitiveCreator<Add<double,int_64,double> >() );
    factory->registerExpression( "add-double-unsignedinteger32", new PrimitiveCreator<Add<double,uint_32,double> >() );
    factory->registerExpression( "add-double-integer32", new PrimitiveCreator<Add<double,int_32,double> >() );
    factory->registerExpression( "add-double-unsignedinteger16", new PrimitiveCreator<Add<double,uint_16,double> >() );
    factory->registerExpression( "add-double-integer16", new PrimitiveCreator<Add<double,int_16,double> >() );
    factory->registerExpression( "add-float-double", new PrimitiveCreator<Add<float,double,double> >() );
    factory->registerExpression( "add-float-float", new PrimitiveCreator<Add<float,float,float> >() );
    factory->registerExpression( "add-float-unsignedinteger64", new PrimitiveCreator<Add<float,uint_64,float> >() );
    factory->registerExpression( "add-float-integer64", new PrimitiveCreator<Add<float,int_64,float> >() );
    factory->registerExpression( "add-float-unsignedinteger32", new PrimitiveCreator<Add<float,uint_32,float> >() );
    factory->registerExpression( "add-float-integer32", new PrimitiveCreator<Add<float,int_32,float> >() );
    factory->registerExpression( "add-float-unsignedinteger16", new PrimitiveCreator<Add<float,uint_16,float> >() );
    factory->registerExpression( "add-float-integer16", new PrimitiveCreator<Add<float,int_16,float> >() );
    factory->registerExpression( "add-unsignedinteger64-double", new PrimitiveCreator<Add<uint_64,double,double> >() );
    factory->registerExpression( "add-unsignedinteger64-float", new PrimitiveCreator<Add<uint_64,float,float> >() );
    factory->registerExpression( "add-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<Add<uint_64,uint_64,uint_64> >() );
    factory->registerExpression( "add-unsignedinteger64-integer64", new PrimitiveCreator<Add<uint_64,int_64,uint_64> >() );
    factory->registerExpression( "add-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<Add<uint_64,uint_32,uint_64> >() );
    factory->registerExpression( "add-unsignedinteger64-integer32", new PrimitiveCreator<Add<uint_64,int_32,uint_64> >() );
    factory->registerExpression( "add-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<Add<uint_64,uint_16,uint_64> >() );
    factory->registerExpression( "add-unsignedinteger64-integer16", new PrimitiveCreator<Add<uint_64,int_16,uint_64> >() );
    factory->registerExpression( "add-integer64-double", new PrimitiveCreator<Add<int_64,double,double> >() );
    factory->registerExpression( "add-integer64-float", new PrimitiveCreator<Add<int_64,float,float> >() );
    factory->registerExpression( "add-integer64-unsignedinteger64", new PrimitiveCreator<Add<int_64,uint_64,uint_64> >() );
    factory->registerExpression( "add-integer64-integer64", new PrimitiveCreator<Add<int_64,int_64,int_64> >() );
    factory->registerExpression( "add-integer64-unsignedinteger32", new PrimitiveCreator<Add<int_64,uint_32,int_64> >() );
    factory->registerExpression( "add-integer64-integer32", new PrimitiveCreator<Add<int_64,int_32,int_64> >() );
    factory->registerExpression( "add-integer64-unsignedinteger16", new PrimitiveCreator<Add<int_64,uint_16,int_64> >() );
    factory->registerExpression( "add-integer64-integer16", new PrimitiveCreator<Add<int_64,int_16,int_64> >() );
    factory->registerExpression( "add-unsignedinteger32-double", new PrimitiveCreator<Add<uint_32,double,double> >() );
    factory->registerExpression( "add-unsignedinteger32-float", new PrimitiveCreator<Add<uint_32,float,float> >() );
    factory->registerExpression( "add-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<Add<uint_32,uint_64,uint_64> >() );
    factory->registerExpression( "add-unsignedinteger32-integer64", new PrimitiveCreator<Add<uint_32,int_64,int_64> >() );
    factory->registerExpression( "add-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<Add<uint_32,uint_32,uint_32> >() );
    factory->registerExpression( "add-unsignedinteger32-integer32", new PrimitiveCreator<Add<uint_32,int_32,uint_32> >() );
    factory->registerExpression( "add-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<Add<uint_32,uint_16,uint_32> >() );
    factory->registerExpression( "add-unsignedinteger32-integer16", new PrimitiveCreator<Add<uint_32,int_16,uint_32> >() );
    factory->registerExpression( "add-integer32-double", new PrimitiveCreator<Add<int_32,double,double> >() );
    factory->registerExpression( "add-integer32-float", new PrimitiveCreator<Add<int_32,float,float> >() );
    factory->registerExpression( "add-integer32-unsignedinteger64", new PrimitiveCreator<Add<int_32,uint_64,uint_64> >() );
    factory->registerExpression( "add-integer32-integer64", new PrimitiveCreator<Add<int_32,int_64,int_64> >() );
    factory->registerExpression( "add-integer32-unsignedinteger32", new PrimitiveCreator<Add<int_32,uint_32,uint_32> >() );
    factory->registerExpression( "add-integer32-integer32", new PrimitiveCreator<Add<int_32,int_32,int_32> >() );
    factory->registerExpression( "add-integer32-unsignedinteger16", new PrimitiveCreator<Add<int_32,uint_16,int_32> >() );
    factory->registerExpression( "add-integer32-integer16", new PrimitiveCreator<Add<int_32,int_16,int_32> >() );
    factory->registerExpression( "add-unsignedinteger16-double", new PrimitiveCreator<Add<uint_16,double,double> >() );
    factory->registerExpression( "add-unsignedinteger16-float", new PrimitiveCreator<Add<uint_16,float,float> >() );
    factory->registerExpression( "add-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<Add<uint_16,uint_64,uint_64> >() );
    factory->registerExpression( "add-unsignedinteger16-integer64", new PrimitiveCreator<Add<uint_16,int_64,int_64> >() );
    factory->registerExpression( "add-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<Add<uint_16,uint_32,uint_32> >() );
    factory->registerExpression( "add-unsignedinteger16-integer32", new PrimitiveCreator<Add<uint_16,int_32,int_32> >() );
    factory->registerExpression( "add-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<Add<uint_16,uint_16,uint_16> >() );
    factory->registerExpression( "add-unsignedinteger16-integer16", new PrimitiveCreator<Add<uint_16,int_16,uint_16> >() );
    factory->registerExpression( "add-integer16-double", new PrimitiveCreator<Add<int_16,double,double> >() );
    factory->registerExpression( "add-integer16-float", new PrimitiveCreator<Add<int_16,float,float> >() );
    factory->registerExpression( "add-integer16-unsignedinteger64", new PrimitiveCreator<Add<int_16,uint_64,uint_64> >() );
    factory->registerExpression( "add-integer16-integer64", new PrimitiveCreator<Add<int_16,int_64,int_64> >() );
    factory->registerExpression( "add-integer16-unsignedinteger32", new PrimitiveCreator<Add<int_16,uint_32,uint_32> >() );
    factory->registerExpression( "add-integer16-integer32", new PrimitiveCreator<Add<int_16,int_32,int_32> >() );
    factory->registerExpression( "add-integer16-unsignedinteger16", new PrimitiveCreator<Add<int_16,uint_16,uint_16> >() );
    factory->registerExpression( "add-integer16-integer16", new PrimitiveCreator<Add<int_16,int_16,int_16> >() );
    factory->registerExpression( "subtract-double-double", new PrimitiveCreator<Subtract<double,double,double> >() );
    factory->registerExpression( "subtract-double-float", new PrimitiveCreator<Subtract<double,float,double> >() );
    factory->registerExpression( "subtract-double-unsignedinteger64", new PrimitiveCreator<Subtract<double,uint_64,double> >() );
    factory->registerExpression( "subtract-double-integer64", new PrimitiveCreator<Subtract<double,int_64,double> >() );
    factory->registerExpression( "subtract-double-unsignedinteger32", new PrimitiveCreator<Subtract<double,uint_32,double> >() );
    factory->registerExpression( "subtract-double-integer32", new PrimitiveCreator<Subtract<double,int_32,double> >() );
    factory->registerExpression( "subtract-double-unsignedinteger16", new PrimitiveCreator<Subtract<double,uint_16,double> >() );
    factory->registerExpression( "subtract-double-integer16", new PrimitiveCreator<Subtract<double,int_16,double> >() );
    factory->registerExpression( "subtract-float-double", new PrimitiveCreator<Subtract<float,double,double> >() );
    factory->registerExpression( "subtract-float-float", new PrimitiveCreator<Subtract<float,float,float> >() );
    factory->registerExpression( "subtract-float-unsignedinteger64", new PrimitiveCreator<Subtract<float,uint_64,float> >() );
    factory->registerExpression( "subtract-float-integer64", new PrimitiveCreator<Subtract<float,int_64,float> >() );
    factory->registerExpression( "subtract-float-unsignedinteger32", new PrimitiveCreator<Subtract<float,uint_32,float> >() );
    factory->registerExpression( "subtract-float-integer32", new PrimitiveCreator<Subtract<float,int_32,float> >() );
    factory->registerExpression( "subtract-float-unsignedinteger16", new PrimitiveCreator<Subtract<float,uint_16,float> >() );
    factory->registerExpression( "subtract-float-integer16", new PrimitiveCreator<Subtract<float,int_16,float> >() );
    factory->registerExpression( "subtract-unsignedinteger64-double", new PrimitiveCreator<Subtract<uint_64,double,double> >() );
    factory->registerExpression( "subtract-unsignedinteger64-float", new PrimitiveCreator<Subtract<uint_64,float,float> >() );
    factory->registerExpression( "subtract-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<Subtract<uint_64,uint_64,uint_64> >() );
    factory->registerExpression( "subtract-unsignedinteger64-integer64", new PrimitiveCreator<Subtract<uint_64,int_64,uint_64> >() );
    factory->registerExpression( "subtract-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<Subtract<uint_64,uint_32,uint_64> >() );
    factory->registerExpression( "subtract-unsignedinteger64-integer32", new PrimitiveCreator<Subtract<uint_64,int_32,uint_64> >() );
    factory->registerExpression( "subtract-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<Subtract<uint_64,uint_16,uint_64> >() );
    factory->registerExpression( "subtract-unsignedinteger64-integer16", new PrimitiveCreator<Subtract<uint_64,int_16,uint_64> >() );
    factory->registerExpression( "subtract-integer64-double", new PrimitiveCreator<Subtract<int_64,double,double> >() );
    factory->registerExpression( "subtract-integer64-float", new PrimitiveCreator<Subtract<int_64,float,float> >() );
    factory->registerExpression( "subtract-integer64-unsignedinteger64", new PrimitiveCreator<Subtract<int_64,uint_64,uint_64> >() );
    factory->registerExpression( "subtract-integer64-integer64", new PrimitiveCreator<Subtract<int_64,int_64,int_64> >() );
    factory->registerExpression( "subtract-integer64-unsignedinteger32", new PrimitiveCreator<Subtract<int_64,uint_32,int_64> >() );
    factory->registerExpression( "subtract-integer64-integer32", new PrimitiveCreator<Subtract<int_64,int_32,int_64> >() );
    factory->registerExpression( "subtract-integer64-unsignedinteger16", new PrimitiveCreator<Subtract<int_64,uint_16,int_64> >() );
    factory->registerExpression( "subtract-integer64-integer16", new PrimitiveCreator<Subtract<int_64,int_16,int_64> >() );
    factory->registerExpression( "subtract-unsignedinteger32-double", new PrimitiveCreator<Subtract<uint_32,double,double> >() );
    factory->registerExpression( "subtract-unsignedinteger32-float", new PrimitiveCreator<Subtract<uint_32,float,float> >() );
    factory->registerExpression( "subtract-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<Subtract<uint_32,uint_64,uint_64> >() );
    factory->registerExpression( "subtract-unsignedinteger32-integer64", new PrimitiveCreator<Subtract<uint_32,int_64,int_64> >() );
    factory->registerExpression( "subtract-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<Subtract<uint_32,uint_32,uint_32> >() );
    factory->registerExpression( "subtract-unsignedinteger32-integer32", new PrimitiveCreator<Subtract<uint_32,int_32,uint_32> >() );
    factory->registerExpression( "subtract-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<Subtract<uint_32,uint_16,uint_32> >() );
    factory->registerExpression( "subtract-unsignedinteger32-integer16", new PrimitiveCreator<Subtract<uint_32,int_16,uint_32> >() );
    factory->registerExpression( "subtract-integer32-double", new PrimitiveCreator<Subtract<int_32,double,double> >() );
    factory->registerExpression( "subtract-integer32-float", new PrimitiveCreator<Subtract<int_32,float,float> >() );
    factory->registerExpression( "subtract-integer32-unsignedinteger64", new PrimitiveCreator<Subtract<int_32,uint_64,uint_64> >() );
    factory->registerExpression( "subtract-integer32-integer64", new PrimitiveCreator<Subtract<int_32,int_64,int_64> >() );
    factory->registerExpression( "subtract-integer32-unsignedinteger32", new PrimitiveCreator<Subtract<int_32,uint_32,uint_32> >() );
    factory->registerExpression( "subtract-integer32-integer32", new PrimitiveCreator<Subtract<int_32,int_32,int_32> >() );
    factory->registerExpression( "subtract-integer32-unsignedinteger16", new PrimitiveCreator<Subtract<int_32,uint_16,int_32> >() );
    factory->registerExpression( "subtract-integer32-integer16", new PrimitiveCreator<Subtract<int_32,int_16,int_32> >() );
    factory->registerExpression( "subtract-unsignedinteger16-double", new PrimitiveCreator<Subtract<uint_16,double,double> >() );
    factory->registerExpression( "subtract-unsignedinteger16-float", new PrimitiveCreator<Subtract<uint_16,float,float> >() );
    factory->registerExpression( "subtract-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<Subtract<uint_16,uint_64,uint_64> >() );
    factory->registerExpression( "subtract-unsignedinteger16-integer64", new PrimitiveCreator<Subtract<uint_16,int_64,int_64> >() );
    factory->registerExpression( "subtract-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<Subtract<uint_16,uint_32,uint_32> >() );
    factory->registerExpression( "subtract-unsignedinteger16-integer32", new PrimitiveCreator<Subtract<uint_16,int_32,int_32> >() );
    factory->registerExpression( "subtract-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<Subtract<uint_16,uint_16,uint_16> >() );
    factory->registerExpression( "subtract-unsignedinteger16-integer16", new PrimitiveCreator<Subtract<uint_16,int_16,uint_16> >() );
    factory->registerExpression( "subtract-integer16-double", new PrimitiveCreator<Subtract<int_16,double,double> >() );
    factory->registerExpression( "subtract-integer16-float", new PrimitiveCreator<Subtract<int_16,float,float> >() );
    factory->registerExpression( "subtract-integer16-unsignedinteger64", new PrimitiveCreator<Subtract<int_16,uint_64,uint_64> >() );
    factory->registerExpression( "subtract-integer16-integer64", new PrimitiveCreator<Subtract<int_16,int_64,int_64> >() );
    factory->registerExpression( "subtract-integer16-unsignedinteger32", new PrimitiveCreator<Subtract<int_16,uint_32,uint_32> >() );
    factory->registerExpression( "subtract-integer16-integer32", new PrimitiveCreator<Subtract<int_16,int_32,int_32> >() );
    factory->registerExpression( "subtract-integer16-unsignedinteger16", new PrimitiveCreator<Subtract<int_16,uint_16,uint_16> >() );
    factory->registerExpression( "subtract-integer16-integer16", new PrimitiveCreator<Subtract<int_16,int_16,int_16> >() );
    factory->registerExpression( "multiply-double-double", new PrimitiveCreator<Multiply<double,double,double> >() );
    factory->registerExpression( "multiply-double-float", new PrimitiveCreator<Multiply<double,float,double> >() );
    factory->registerExpression( "multiply-double-unsignedinteger64", new PrimitiveCreator<Multiply<double,uint_64,double> >() );
    factory->registerExpression( "multiply-double-integer64", new PrimitiveCreator<Multiply<double,int_64,double> >() );
    factory->registerExpression( "multiply-double-unsignedinteger32", new PrimitiveCreator<Multiply<double,uint_32,double> >() );
    factory->registerExpression( "multiply-double-integer32", new PrimitiveCreator<Multiply<double,int_32,double> >() );
    factory->registerExpression( "multiply-double-unsignedinteger16", new PrimitiveCreator<Multiply<double,uint_16,double> >() );
    factory->registerExpression( "multiply-double-integer16", new PrimitiveCreator<Multiply<double,int_16,double> >() );
    factory->registerExpression( "multiply-float-double", new PrimitiveCreator<Multiply<float,double,double> >() );
    factory->registerExpression( "multiply-float-float", new PrimitiveCreator<Multiply<float,float,float> >() );
    factory->registerExpression( "multiply-float-unsignedinteger64", new PrimitiveCreator<Multiply<float,uint_64,float> >() );
    factory->registerExpression( "multiply-float-integer64", new PrimitiveCreator<Multiply<float,int_64,float> >() );
    factory->registerExpression( "multiply-float-unsignedinteger32", new PrimitiveCreator<Multiply<float,uint_32,float> >() );
    factory->registerExpression( "multiply-float-integer32", new PrimitiveCreator<Multiply<float,int_32,float> >() );
    factory->registerExpression( "multiply-float-unsignedinteger16", new PrimitiveCreator<Multiply<float,uint_16,float> >() );
    factory->registerExpression( "multiply-float-integer16", new PrimitiveCreator<Multiply<float,int_16,float> >() );
    factory->registerExpression( "multiply-unsignedinteger64-double", new PrimitiveCreator<Multiply<uint_64,double,double> >() );
    factory->registerExpression( "multiply-unsignedinteger64-float", new PrimitiveCreator<Multiply<uint_64,float,float> >() );
    factory->registerExpression( "multiply-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<Multiply<uint_64,uint_64,uint_64> >() );
    factory->registerExpression( "multiply-unsignedinteger64-integer64", new PrimitiveCreator<Multiply<uint_64,int_64,uint_64> >() );
    factory->registerExpression( "multiply-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<Multiply<uint_64,uint_32,uint_64> >() );
    factory->registerExpression( "multiply-unsignedinteger64-integer32", new PrimitiveCreator<Multiply<uint_64,int_32,uint_64> >() );
    factory->registerExpression( "multiply-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<Multiply<uint_64,uint_16,uint_64> >() );
    factory->registerExpression( "multiply-unsignedinteger64-integer16", new PrimitiveCreator<Multiply<uint_64,int_16,uint_64> >() );
    factory->registerExpression( "multiply-integer64-double", new PrimitiveCreator<Multiply<int_64,double,double> >() );
    factory->registerExpression( "multiply-integer64-float", new PrimitiveCreator<Multiply<int_64,float,float> >() );
    factory->registerExpression( "multiply-integer64-unsignedinteger64", new PrimitiveCreator<Multiply<int_64,uint_64,uint_64> >() );
    factory->registerExpression( "multiply-integer64-integer64", new PrimitiveCreator<Multiply<int_64,int_64,int_64> >() );
    factory->registerExpression( "multiply-integer64-unsignedinteger32", new PrimitiveCreator<Multiply<int_64,uint_32,int_64> >() );
    factory->registerExpression( "multiply-integer64-integer32", new PrimitiveCreator<Multiply<int_64,int_32,int_64> >() );
    factory->registerExpression( "multiply-integer64-unsignedinteger16", new PrimitiveCreator<Multiply<int_64,uint_16,int_64> >() );
    factory->registerExpression( "multiply-integer64-integer16", new PrimitiveCreator<Multiply<int_64,int_16,int_64> >() );
    factory->registerExpression( "multiply-unsignedinteger32-double", new PrimitiveCreator<Multiply<uint_32,double,double> >() );
    factory->registerExpression( "multiply-unsignedinteger32-float", new PrimitiveCreator<Multiply<uint_32,float,float> >() );
    factory->registerExpression( "multiply-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<Multiply<uint_32,uint_64,uint_64> >() );
    factory->registerExpression( "multiply-unsignedinteger32-integer64", new PrimitiveCreator<Multiply<uint_32,int_64,int_64> >() );
    factory->registerExpression( "multiply-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<Multiply<uint_32,uint_32,uint_32> >() );
    factory->registerExpression( "multiply-unsignedinteger32-integer32", new PrimitiveCreator<Multiply<uint_32,int_32,uint_32> >() );
    factory->registerExpression( "multiply-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<Multiply<uint_32,uint_16,uint_32> >() );
    factory->registerExpression( "multiply-unsignedinteger32-integer16", new PrimitiveCreator<Multiply<uint_32,int_16,uint_32> >() );
    factory->registerExpression( "multiply-integer32-double", new PrimitiveCreator<Multiply<int_32,double,double> >() );
    factory->registerExpression( "multiply-integer32-float", new PrimitiveCreator<Multiply<int_32,float,float> >() );
    factory->registerExpression( "multiply-integer32-unsignedinteger64", new PrimitiveCreator<Multiply<int_32,uint_64,uint_64> >() );
    factory->registerExpression( "multiply-integer32-integer64", new PrimitiveCreator<Multiply<int_32,int_64,int_64> >() );
    factory->registerExpression( "multiply-integer32-unsignedinteger32", new PrimitiveCreator<Multiply<int_32,uint_32,uint_32> >() );
    factory->registerExpression( "multiply-integer32-integer32", new PrimitiveCreator<Multiply<int_32,int_32,int_32> >() );
    factory->registerExpression( "multiply-integer32-unsignedinteger16", new PrimitiveCreator<Multiply<int_32,uint_16,int_32> >() );
    factory->registerExpression( "multiply-integer32-integer16", new PrimitiveCreator<Multiply<int_32,int_16,int_32> >() );
    factory->registerExpression( "multiply-unsignedinteger16-double", new PrimitiveCreator<Multiply<uint_16,double,double> >() );
    factory->registerExpression( "multiply-unsignedinteger16-float", new PrimitiveCreator<Multiply<uint_16,float,float> >() );
    factory->registerExpression( "multiply-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<Multiply<uint_16,uint_64,uint_64> >() );
    factory->registerExpression( "multiply-unsignedinteger16-integer64", new PrimitiveCreator<Multiply<uint_16,int_64,int_64> >() );
    factory->registerExpression( "multiply-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<Multiply<uint_16,uint_32,uint_32> >() );
    factory->registerExpression( "multiply-unsignedinteger16-integer32", new PrimitiveCreator<Multiply<uint_16,int_32,int_32> >() );
    factory->registerExpression( "multiply-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<Multiply<uint_16,uint_16,uint_16> >() );
    factory->registerExpression( "multiply-unsignedinteger16-integer16", new PrimitiveCreator<Multiply<uint_16,int_16,uint_16> >() );
    factory->registerExpression( "multiply-integer16-double", new PrimitiveCreator<Multiply<int_16,double,double> >() );
    factory->registerExpression( "multiply-integer16-float", new PrimitiveCreator<Multiply<int_16,float,float> >() );
    factory->registerExpression( "multiply-integer16-unsignedinteger64", new PrimitiveCreator<Multiply<int_16,uint_64,uint_64> >() );
    factory->registerExpression( "multiply-integer16-integer64", new PrimitiveCreator<Multiply<int_16,int_64,int_64> >() );
    factory->registerExpression( "multiply-integer16-unsignedinteger32", new PrimitiveCreator<Multiply<int_16,uint_32,uint_32> >() );
    factory->registerExpression( "multiply-integer16-integer32", new PrimitiveCreator<Multiply<int_16,int_32,int_32> >() );
    factory->registerExpression( "multiply-integer16-unsignedinteger16", new PrimitiveCreator<Multiply<int_16,uint_16,uint_16> >() );
    factory->registerExpression( "multiply-integer16-integer16", new PrimitiveCreator<Multiply<int_16,int_16,int_16> >() );
    factory->registerExpression( "division-double-double", new PrimitiveCreator<Divide<double,double,double> >() );
    factory->registerExpression( "division-double-float", new PrimitiveCreator<Divide<double,float,double> >() );
    factory->registerExpression( "division-double-unsignedinteger64", new PrimitiveCreator<Divide<double,uint_64,double> >() );
    factory->registerExpression( "division-double-integer64", new PrimitiveCreator<Divide<double,int_64,double> >() );
    factory->registerExpression( "division-double-unsignedinteger32", new PrimitiveCreator<Divide<double,uint_32,double> >() );
    factory->registerExpression( "division-double-integer32", new PrimitiveCreator<Divide<double,int_32,double> >() );
    factory->registerExpression( "division-double-unsignedinteger16", new PrimitiveCreator<Divide<double,uint_16,double> >() );
    factory->registerExpression( "division-double-integer16", new PrimitiveCreator<Divide<double,int_16,double> >() );
    factory->registerExpression( "division-float-double", new PrimitiveCreator<Divide<float,double,double> >() );
    factory->registerExpression( "division-float-float", new PrimitiveCreator<Divide<float,float,float> >() );
    factory->registerExpression( "division-float-unsignedinteger64", new PrimitiveCreator<Divide<float,uint_64,float> >() );
    factory->registerExpression( "division-float-integer64", new PrimitiveCreator<Divide<float,int_64,float> >() );
    factory->registerExpression( "division-float-unsignedinteger32", new PrimitiveCreator<Divide<float,uint_32,float> >() );
    factory->registerExpression( "division-float-integer32", new PrimitiveCreator<Divide<float,int_32,float> >() );
    factory->registerExpression( "division-float-unsignedinteger16", new PrimitiveCreator<Divide<float,uint_16,float> >() );
    factory->registerExpression( "division-float-integer16", new PrimitiveCreator<Divide<float,int_16,float> >() );
    factory->registerExpression( "division-unsignedinteger64-double", new PrimitiveCreator<Divide<uint_64,double,double> >() );
    factory->registerExpression( "division-unsignedinteger64-float", new PrimitiveCreator<Divide<uint_64,float,float> >() );
    factory->registerExpression( "division-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<Divide<uint_64,uint_64,uint_64> >() );
    factory->registerExpression( "division-unsignedinteger64-integer64", new PrimitiveCreator<Divide<uint_64,int_64,uint_64> >() );
    factory->registerExpression( "division-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<Divide<uint_64,uint_32,uint_64> >() );
    factory->registerExpression( "division-unsignedinteger64-integer32", new PrimitiveCreator<Divide<uint_64,int_32,uint_64> >() );
    factory->registerExpression( "division-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<Divide<uint_64,uint_16,uint_64> >() );
    factory->registerExpression( "division-unsignedinteger64-integer16", new PrimitiveCreator<Divide<uint_64,int_16,uint_64> >() );
    factory->registerExpression( "division-integer64-double", new PrimitiveCreator<Divide<int_64,double,double> >() );
    factory->registerExpression( "division-integer64-float", new PrimitiveCreator<Divide<int_64,float,float> >() );
    factory->registerExpression( "division-integer64-unsignedinteger64", new PrimitiveCreator<Divide<int_64,uint_64,uint_64> >() );
    factory->registerExpression( "division-integer64-integer64", new PrimitiveCreator<Divide<int_64,int_64,int_64> >() );
    factory->registerExpression( "division-integer64-unsignedinteger32", new PrimitiveCreator<Divide<int_64,uint_32,int_64> >() );
    factory->registerExpression( "division-integer64-integer32", new PrimitiveCreator<Divide<int_64,int_32,int_64> >() );
    factory->registerExpression( "division-integer64-unsignedinteger16", new PrimitiveCreator<Divide<int_64,uint_16,int_64> >() );
    factory->registerExpression( "division-integer64-integer16", new PrimitiveCreator<Divide<int_64,int_16,int_64> >() );
    factory->registerExpression( "division-unsignedinteger32-double", new PrimitiveCreator<Divide<uint_32,double,double> >() );
    factory->registerExpression( "division-unsignedinteger32-float", new PrimitiveCreator<Divide<uint_32,float,float> >() );
    factory->registerExpression( "division-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<Divide<uint_32,uint_64,uint_64> >() );
    factory->registerExpression( "division-unsignedinteger32-integer64", new PrimitiveCreator<Divide<uint_32,int_64,int_64> >() );
    factory->registerExpression( "division-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<Divide<uint_32,uint_32,uint_32> >() );
    factory->registerExpression( "division-unsignedinteger32-integer32", new PrimitiveCreator<Divide<uint_32,int_32,uint_32> >() );
    factory->registerExpression( "division-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<Divide<uint_32,uint_16,uint_32> >() );
    factory->registerExpression( "division-unsignedinteger32-integer16", new PrimitiveCreator<Divide<uint_32,int_16,uint_32> >() );
    factory->registerExpression( "division-integer32-double", new PrimitiveCreator<Divide<int_32,double,double> >() );
    factory->registerExpression( "division-integer32-float", new PrimitiveCreator<Divide<int_32,float,float> >() );
    factory->registerExpression( "division-integer32-unsignedinteger64", new PrimitiveCreator<Divide<int_32,uint_64,uint_64> >() );
    factory->registerExpression( "division-integer32-integer64", new PrimitiveCreator<Divide<int_32,int_64,int_64> >() );
    factory->registerExpression( "division-integer32-unsignedinteger32", new PrimitiveCreator<Divide<int_32,uint_32,uint_32> >() );
    factory->registerExpression( "division-integer32-integer32", new PrimitiveCreator<Divide<int_32,int_32,int_32> >() );
    factory->registerExpression( "division-integer32-unsignedinteger16", new PrimitiveCreator<Divide<int_32,uint_16,int_32> >() );
    factory->registerExpression( "division-integer32-integer16", new PrimitiveCreator<Divide<int_32,int_16,int_32> >() );
    factory->registerExpression( "division-unsignedinteger16-double", new PrimitiveCreator<Divide<uint_16,double,double> >() );
    factory->registerExpression( "division-unsignedinteger16-float", new PrimitiveCreator<Divide<uint_16,float,float> >() );
    factory->registerExpression( "division-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<Divide<uint_16,uint_64,uint_64> >() );
    factory->registerExpression( "division-unsignedinteger16-integer64", new PrimitiveCreator<Divide<uint_16,int_64,int_64> >() );
    factory->registerExpression( "division-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<Divide<uint_16,uint_32,uint_32> >() );
    factory->registerExpression( "division-unsignedinteger16-integer32", new PrimitiveCreator<Divide<uint_16,int_32,int_32> >() );
    factory->registerExpression( "division-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<Divide<uint_16,uint_16,uint_16> >() );
    factory->registerExpression( "division-unsignedinteger16-integer16", new PrimitiveCreator<Divide<uint_16,int_16,uint_16> >() );
    factory->registerExpression( "division-integer16-double", new PrimitiveCreator<Divide<int_16,double,double> >() );
    factory->registerExpression( "division-integer16-float", new PrimitiveCreator<Divide<int_16,float,float> >() );
    factory->registerExpression( "division-integer16-unsignedinteger64", new PrimitiveCreator<Divide<int_16,uint_64,uint_64> >() );
    factory->registerExpression( "division-integer16-integer64", new PrimitiveCreator<Divide<int_16,int_64,int_64> >() );
    factory->registerExpression( "division-integer16-unsignedinteger32", new PrimitiveCreator<Divide<int_16,uint_32,uint_32> >() );
    factory->registerExpression( "division-integer16-integer32", new PrimitiveCreator<Divide<int_16,int_32,int_32> >() );
    factory->registerExpression( "division-integer16-unsignedinteger16", new PrimitiveCreator<Divide<int_16,uint_16,uint_16> >() );
    factory->registerExpression( "division-integer16-integer16", new PrimitiveCreator<Divide<int_16,int_16,int_16> >() );
    factory->registerExpression( "modulo-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<Modulo<uint_64,uint_64,uint_64> >() );
    factory->registerExpression( "modulo-unsignedinteger64-integer64", new PrimitiveCreator<Modulo<uint_64,int_64,uint_64> >() );
    factory->registerExpression( "modulo-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<Modulo<uint_64,uint_32,uint_64> >() );
    factory->registerExpression( "modulo-unsignedinteger64-integer32", new PrimitiveCreator<Modulo<uint_64,int_32,uint_64> >() );
    factory->registerExpression( "modulo-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<Modulo<uint_64,uint_16,uint_64> >() );
    factory->registerExpression( "modulo-unsignedinteger64-integer16", new PrimitiveCreator<Modulo<uint_64,int_16,uint_64> >() );
    factory->registerExpression( "modulo-integer64-unsignedinteger64", new PrimitiveCreator<Modulo<int_64,uint_64,uint_64> >() );
    factory->registerExpression( "modulo-integer64-integer64", new PrimitiveCreator<Modulo<int_64,int_64,int_64> >() );
    factory->registerExpression( "modulo-integer64-unsignedinteger32", new PrimitiveCreator<Modulo<int_64,uint_32,int_64> >() );
    factory->registerExpression( "modulo-integer64-integer32", new PrimitiveCreator<Modulo<int_64,int_32,int_64> >() );
    factory->registerExpression( "modulo-integer64-unsignedinteger16", new PrimitiveCreator<Modulo<int_64,uint_16,int_64> >() );
    factory->registerExpression( "modulo-integer64-integer16", new PrimitiveCreator<Modulo<int_64,int_16,int_64> >() );
    factory->registerExpression( "modulo-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<Modulo<uint_32,uint_64,uint_64> >() );
    factory->registerExpression( "modulo-unsignedinteger32-integer64", new PrimitiveCreator<Modulo<uint_32,int_64,int_64> >() );
    factory->registerExpression( "modulo-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<Modulo<uint_32,uint_32,uint_32> >() );
    factory->registerExpression( "modulo-unsignedinteger32-integer32", new PrimitiveCreator<Modulo<uint_32,int_32,uint_32> >() );
    factory->registerExpression( "modulo-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<Modulo<uint_32,uint_16,uint_32> >() );
    factory->registerExpression( "modulo-unsignedinteger32-integer16", new PrimitiveCreator<Modulo<uint_32,int_16,uint_32> >() );
    factory->registerExpression( "modulo-integer32-unsignedinteger64", new PrimitiveCreator<Modulo<int_32,uint_64,uint_64> >() );
    factory->registerExpression( "modulo-integer32-integer64", new PrimitiveCreator<Modulo<int_32,int_64,int_64> >() );
    factory->registerExpression( "modulo-integer32-unsignedinteger32", new PrimitiveCreator<Modulo<int_32,uint_32,uint_32> >() );
    factory->registerExpression( "modulo-integer32-integer32", new PrimitiveCreator<Modulo<int_32,int_32,int_32> >() );
    factory->registerExpression( "modulo-integer32-unsignedinteger16", new PrimitiveCreator<Modulo<int_32,uint_16,int_32> >() );
    factory->registerExpression( "modulo-integer32-integer16", new PrimitiveCreator<Modulo<int_32,int_16,int_32> >() );
    factory->registerExpression( "modulo-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<Modulo<uint_16,uint_64,uint_64> >() );
    factory->registerExpression( "modulo-unsignedinteger16-integer64", new PrimitiveCreator<Modulo<uint_16,int_64,int_64> >() );
    factory->registerExpression( "modulo-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<Modulo<uint_16,uint_32,uint_32> >() );
    factory->registerExpression( "modulo-unsignedinteger16-integer32", new PrimitiveCreator<Modulo<uint_16,int_32,int_32> >() );
    factory->registerExpression( "modulo-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<Modulo<uint_16,uint_16,uint_16> >() );
    factory->registerExpression( "modulo-unsignedinteger16-integer16", new PrimitiveCreator<Modulo<uint_16,int_16,uint_16> >() );
    factory->registerExpression( "modulo-integer16-unsignedinteger64", new PrimitiveCreator<Modulo<int_16,uint_64,uint_64> >() );
    factory->registerExpression( "modulo-integer16-integer64", new PrimitiveCreator<Modulo<int_16,int_64,int_64> >() );
    factory->registerExpression( "modulo-integer16-unsignedinteger32", new PrimitiveCreator<Modulo<int_16,uint_32,uint_32> >() );
    factory->registerExpression( "modulo-integer16-integer32", new PrimitiveCreator<Modulo<int_16,int_32,int_32> >() );
    factory->registerExpression( "modulo-integer16-unsignedinteger16", new PrimitiveCreator<Modulo<int_16,uint_16,uint_16> >() );
    factory->registerExpression( "modulo-integer16-integer16", new PrimitiveCreator<Modulo<int_16,int_16,int_16> >() );
    factory->registerExpression("power-unsignedinteger64-unsignedinteger64", new PrimitiveCreator<Power<uint_64,uint_64,uint_64> >() );
    factory->registerExpression("power-unsignedinteger64-integer64", new PrimitiveCreator<Power<uint_64,int_64,uint_64> >() );
    factory->registerExpression("power-unsignedinteger64-unsignedinteger32", new PrimitiveCreator<Power<uint_64,uint_32,uint_64> >() );
    factory->registerExpression("power-unsignedinteger64-integer32", new PrimitiveCreator<Power<uint_64,int_32,uint_64> >() );
    factory->registerExpression("power-unsignedinteger64-unsignedinteger16", new PrimitiveCreator<Power<uint_64,uint_16,uint_64> >() );
    factory->registerExpression("power-unsignedinteger64-integer16", new PrimitiveCreator<Power<uint_64,int_16,uint_64> >() );
    factory->registerExpression("power-integer64-unsignedinteger64", new PrimitiveCreator<Power<int_64,uint_64,uint_64> >() );
    factory->registerExpression("power-integer64-integer64", new PrimitiveCreator<Power<int_64,int_64,int_64> >() );
    factory->registerExpression("power-integer64-unsignedinteger32", new PrimitiveCreator<Power<int_64,uint_32,int_64> >() );
    factory->registerExpression("power-integer64-integer32", new PrimitiveCreator<Power<int_64,int_32,int_64> >() );
    factory->registerExpression("power-integer64-unsignedinteger16", new PrimitiveCreator<Power<int_64,uint_16,int_64> >() );
    factory->registerExpression("power-integer64-integer16", new PrimitiveCreator<Power<int_64,int_16,int_64> >() );
    factory->registerExpression("power-unsignedinteger32-unsignedinteger64", new PrimitiveCreator<Power<uint_32,uint_64,uint_64> >() );
    factory->registerExpression("power-unsignedinteger32-integer64", new PrimitiveCreator<Power<uint_32,int_64,int_64> >() );
    factory->registerExpression("power-unsignedinteger32-unsignedinteger32", new PrimitiveCreator<Power<uint_32,uint_32,uint_32> >() );
    factory->registerExpression("power-unsignedinteger32-integer32", new PrimitiveCreator<Power<uint_32,int_32,uint_32> >() );
    factory->registerExpression("power-unsignedinteger32-unsignedinteger16", new PrimitiveCreator<Power<uint_32,uint_16,uint_32> >() );
    factory->registerExpression("power-unsignedinteger32-integer16", new PrimitiveCreator<Power<uint_32,int_16,uint_32> >() );
    factory->registerExpression("power-integer32-unsignedinteger64", new PrimitiveCreator<Power<int_32,uint_64,uint_64> >() );
    factory->registerExpression("power-integer32-integer64", new PrimitiveCreator<Power<int_32,int_64,int_64> >() );
    factory->registerExpression("power-integer32-unsignedinteger32", new PrimitiveCreator<Power<int_32,uint_32,uint_32> >() );
    factory->registerExpression("power-integer32-integer32", new PrimitiveCreator<Power<int_32,int_32,int_32> >() );
    factory->registerExpression("power-integer32-unsignedinteger16", new PrimitiveCreator<Power<int_32,uint_16,int_32> >() );
    factory->registerExpression("power-integer32-integer16", new PrimitiveCreator<Power<int_32,int_16,int_32> >() );
    factory->registerExpression("power-unsignedinteger16-unsignedinteger64", new PrimitiveCreator<Power<uint_16,uint_64,uint_64> >() );
    factory->registerExpression("power-unsignedinteger16-integer64", new PrimitiveCreator<Power<uint_16,int_64,int_64> >() );
    factory->registerExpression("power-unsignedinteger16-unsignedinteger32", new PrimitiveCreator<Power<uint_16,uint_32,uint_32> >() );
    factory->registerExpression("power-unsignedinteger16-integer32", new PrimitiveCreator<Power<uint_16,int_32,int_32> >() );
    factory->registerExpression("power-unsignedinteger16-unsignedinteger16", new PrimitiveCreator<Power<uint_16,uint_16,uint_16> >() );
    factory->registerExpression("power-unsignedinteger16-integer16", new PrimitiveCreator<Power<uint_16,int_16,uint_16> >() );
    factory->registerExpression("power-integer16-unsignedinteger64", new PrimitiveCreator<Power<int_16,uint_64,uint_64> >() );
    factory->registerExpression("power-integer16-integer64", new PrimitiveCreator<Power<int_16,int_64,int_64> >() );
    factory->registerExpression("power-integer16-unsignedinteger32", new PrimitiveCreator<Power<int_16,uint_32,uint_32> >() );
    factory->registerExpression("power-integer16-integer32", new PrimitiveCreator<Power<int_16,int_32,int_32> >() );
    factory->registerExpression("power-integer16-unsignedinteger16", new PrimitiveCreator<Power<int_16,uint_16,uint_16> >() );
    factory->registerExpression("power-integer16-integer16", new PrimitiveCreator<Power<int_16,int_16,int_16> >() );
    
    RULEENGINE_STACK_TRACE_EXIT
}
};
/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
