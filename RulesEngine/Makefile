all:	
	rm -rf Lib/*.o
	rm -rf Bin/*
	g++ -m64 -fPIC -c -o Lib/ArithmeticOperations.o Source/ruleengine/framework/ArithmeticOperations.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/BaseOperations.o Source/ruleengine/framework/BaseTypes.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/CastOperations.o Source/ruleengine/framework/CastOperations.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/ComparisonOperations.o Source/ruleengine/framework/ComparisonOperations.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/ConversionOperations.o Source/ruleengine/framework/ConversionOperations.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/ExpressionFactory.o Source/ruleengine/framework/ExpressionFactory.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/LogicalOperations.o Source/ruleengine/framework/LogicalOperations.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/Action.o Source/ruleengine/internal/Action.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/Condition.o Source/ruleengine/internal/Condition.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/MemoryPool.o Source/ruleengine/internal/MemoryPool.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/Rule.o Source/ruleengine/internal/Rule.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/RulePacket.o Source/ruleengine/internal/RulePacket.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/FactInterfaceInputContext.o Source/ruleengine/internal/FactInterfaceInputContext.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/SPS/trunk/SharedObjects/Generator/Include/ -I/app/bmobsps/SPS/trunk/SharedObjects/RequestRetrier/Include/  -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/EnginePool.o Source/ruleengine/engine/EnginePool.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/RuleConfig.o Source/ruleengine/engine/RuleConfig.cpp -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/
	g++ -m64 -fPIC -c -o Lib/RuleEngine.o Source/ruleengine/engine/RuleEngine.cpp  -I./Include/ -I/app/bmobsps/SPS/trunk/Include/ -I/app/bmobsps/Softwares/xerces-c-2.7.0-all-src/xerces-c-2.7.0-src/include/  -I/app/bmobsps/SPS/trunk/SharedObjects/Generator/Include -I/app/bmobsps/SPS/trunk/SharedObjects/RequestRetrier/Include/

	ar rcs Lib/librulesengine.a Lib/*.o /app/bmobsps/SPS/trunk/ABL_Date.o
	rm -rf Lib/*.o
