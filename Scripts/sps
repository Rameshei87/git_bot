#!/bin/bash

flag=0
case $1 in
	start)
		flag=1
		;;
	stop)	
		flag=2
		;;
	restart)
		flag=3
		;;
	*)
		echo "sps {start|stop|restart}"
		exit
		;;
esac	
SPS_HOME=/home/mtny/Tecnotree/SPS
ORACLE_HOME=/home/orcl10g/product/client_1

SESSION_LAYER_HOME=${SPS_HOME}/SessionLayer
ADAPTER_HOME=${SPS_HOME}/OutputAdapter
LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${SPS_HOME}/Lib:${ORACLE_HOME}/lib

export SPS_HOME
export SESSION_LAYER_HOME
export ADAPTER_HOME
clear;

exit_start_script() {
	clear;
	echo -e "\033[1;31mSPS Start Failure\033[0m"
	echo -e "\n\033[1:20mReason : \033[0m"	
}
sharedObjName="Check list file missing / Lib directory missing"
check_shared_obj() {
	if [ ! -r $1 ]
	then
		return 1
	fi
	if [ ! -d $2 ]
	then
		return 1
	fi
	sharedObjCount=`cat $1 | wc -l`
	index=1
	#soNotFound=0
	while [ ${index} -le ${sharedObjCount} ]
	do
	        sharedObjName=`head -${index} $1 | tail -1`
     	 	index=`expr ${index} + 1`
      	  	if [ ! -r $2/${sharedObjName} ]
      	  	then
			return 1
      	  	fi
	done
	return 0	
}

check_sessionlayer_files() {
	
	if [ ! -x ${SESSION_LAYER_HOME}/Bin/Session.exe ]
	then
		
		return 1
	else
		if [ ! -r ${SESSION_LAYER_HOME}/Conf/db.conf ]
		then
			return 1
		fi
		return 0
	fi
	
}

check_output_adapter_files() {
	if [ ! -x ${ADAPTER_HOME}/Bin/OutputAdapter.exe ]
        then

                return 1
        else
                if [ ! -r ${ADAPTER_HOME}/Conf/db.conf ]
                then
                        return 1
                fi
                return 0
        fi
}

check_db_connectivity() {
	if [ ! -r $1 ]
	then
		return 1
	fi
	userName=`head -1 $1 | cut -d ":" -f2 | /usr/bin/tr -d ' '`
	passWord=`head -1 $1 | cut -d ":" -f3 | /usr/bin/tr -d ' '`
	schema=`head -1 $1 | cut -d ":" -f4 | /usr/bin/tr -d ' '`
	returnVal=`sqlplus -s -L ${userName}/${passWord}@${schema} 2> /dev/null << EOF
        		EOF`
	return $?
}

echo -e "\033[41m\t\t\t\tTecnotree SPS\033[0m"
#echo -e "\033[1;31m\t\t\t\t-------------\033[0m"

start() {
	processCount=`ps -aef | grep SPSScheduler | grep -v grep | wc -l`
	if [ ${processCount} -ne 0 ]
	then
		pid=`ps -aef | grep SPSScheduler | grep -v grep | awk '{ print $2 }'`
		echo -e "\033[1;20mProcess running with pid \033[1;32m${pid}\033[0m\033[1;20m"	
		exit
	fi
	echo -e "\033[1;20m1) Checking for database configuration\033[0m\c"
	filePresent=0
	if [ -r ${SPS_HOME}/Conf/db.conf ]
	then
		filePresent=1
	fi
	if [ ${filePresent} -ne 1 ]
	then
		echo -e "\033[1;20m \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		echo -e "\033[1;20m \t \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m2) Checking for schema definition\033[0m\c"
	filePresent=0
	if [ -r ${SPS_HOME}/Conf/SPS.xsd ]
	then
		filePresent=1
	fi
	if [ ${filePresent} -ne 1 ]
	then
		echo -e "\033[1;20m \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		filePresent=0
		if [ -r /tmp/SPS.xsd ]
		then
			`cp -p ${SPS_HOME}/Conf/SPS.xsd /tmp/SPS.xsd`
			filePresent=1
		else
			`cp -p ${SPS_HOME}/Conf/SPS.xsd /tmp/SPS.xsd`
			filePresent=1
		fi
		if [ ${filePresent} -ne 1 ]
		then
			echo -e "\033[1;20m \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
		else
			echo -e "\033[1;20m \t \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
		fi	
	fi
	tput sgr0

	echo -e "\033[1;20m3) Checking for HTTP server\033[0m\c"

	filePresent=`netstat -na | grep 80 | grep LISTEN | wc -l`

	if [ ${filePresent} -eq 0 ]
	then
		echo -e "\033[1;20m \t \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		echo -e "\033[1;20m \t \t \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m4) Checking database connectivity\033[0m\c"

	check_db_connectivity ${SPS_HOME}/Conf/db.conf

	if [ $? -ne 0 ]
	then
		echo -e "\033[1;20m \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		echo -e "\033[1;20m \t \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m5) Checking for SPS libraries\033[0m\c"

	check_shared_obj ${SPS_HOME}/Conf/StartupCheckList ${SPS_HOME}/Lib

	if [ $? -ne 0 ]
	then
		echo -e "\033[1;20m \t \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
		echo -e "\n\033[1;20mMissing Library : \033[1;31m${sharedObjName} \033[0m\n"
	else
		echo -e "\033[1;20m \t \t \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m6) Checking for Session Layer for Web Services\033[0m\c"

	check_sessionlayer_files

	if [ $? -ne 0 ]
	then
		echo -e "\033[1;20m \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		echo -e "\033[1;20m \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m7) Checking for Session Layer database connectivity\033[0m\c"

	check_db_connectivity ${SESSION_LAYER_HOME}/Conf/db.conf

	if [ $? -ne 0 ]
	then
		echo -e "\033[1;20m \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		echo -e "\033[1;20m \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m8) Checking for Output Adapters\033[0m\c"

	check_output_adapter_files

	if [ $? -ne 0 ]
	then
		echo -e "\033[1;20m \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		echo -e "\033[1;20m \t \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m9) Checking for Adapter database connectivity\033[0m\c"

	check_db_connectivity ${ADAPTER_HOME}/Conf/db.conf

	if [ $? -ne 0 ]
	then
		echo -e "\033[1;20m \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
	else
		echo -e "\033[1;20m \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0

	echo -e "\033[1;20m10) Checking for Adapter libraries\033[0m\c"
	check_shared_obj ${ADAPTER_HOME}/Conf/StartupCheckList ${ADAPTER_HOME}/Lib
	if [ $? -ne 0 ]
	then
		echo -e "\033[1;20m \t \t \t \t [ \033[1;31mFAILED \033[0m\033[1;20m]\n"
		echo -e "\n\033[1;20mMissing Library : \033[1;31m${sharedObjName} \033[0m\n"
	else
		echo -e "\033[1;20m \t \t \t \t [ \033[1;32mOK \033[0m\033[1;20m]\n"
	fi
	tput sgr0
	crontabtempfile=${SPS_HOME}/crontabtempfile
	crontabfile=${SPS_HOME}/crontabfile
	spsCrontabEntry=`crontab -l 2>/dev/null | grep -w "startsps" | grep -v grep | wc -l`

	if [ ${spsCrontabEntry} -ge 1 ]
	then
		echo "System will be started"
	else
		echo "1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59 * * * * $SPS_HOME/Bin/startsps ${SPS_HOME} ${ORACLE_HOME} ${LD_LIBRARY_PATH} >> $SPS_HOME/Logs/sps_cron_log 2>&1" > $crontabtempfile
	fi

	if [ -f ${crontabtempfile} ]
	then
		`crontab -l 2> /dev/null > ${crontabfile}`
		cat ${crontabtempfile} >> ${crontabfile}
		crontab $crontabfile
		echo "System will be started"
	fi
	
	crontabtempfile=${SESSION_LAYER_HOME}/crontabtempfile
	crontabfile=${SESSION_LAYER_HOME}/crontabfile
	sessioncrontab=`crontab -l 2>/dev/null | grep -w "startsession" | grep -v grep | wc -l`
	if [ -f ${SESSION_LAYER_HOME}/stop ]
	then
		rm -f ${SESSION_LAYER_HOME}/stop
	fi
	if [ ${sessioncrontab} -ge 1 ]
        then
                echo "System will be started"
        else
                echo "2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58 * * * * ${SESSION_LAYER_HOME}/Bin/startsession ${SESSION_LAYER_HOME} ${ORACLE_HOME} ${LD_LIBRARY_PATH} >> $SPS_HOME/Logs/ses_cron_log 2>&1" > $crontabtempfile
        fi
	if [ -f ${crontabtempfile} ]
        then
                `crontab -l 2> /dev/null > ${crontabfile}`
                cat ${crontabtempfile} >> ${crontabfile}
                crontab $crontabfile
                echo "System will be started"
        fi
}

stopSessionLayer() {
	crontabfile=${SESSION_LAYER_HOME}/crontabfile
        crontabtempfile=${SESSION_LAYER_HOME}/crontabtempfile
        processCrontabCount=`crontab -l 2> /dev/null| grep -w startsession | grep -v grep | wc -l`
        if [ ${processCrontabCount} -ge 1 ]
        then
		`crontab -l 2> /dev/null| grep -v startsession > ${crontabfile}`

                 szFileSize=0
                 szFileSize=`cat ${crontabfile} | wc -l`

                 if [ $szFileSize -ge 1 ]
                 then
                        crontab $crontabfile
                 else
                        crontab -r
                        echo "All crontab entries removed"
                 fi
        fi
	processCount=`ps -aef | grep Session.exe | grep -v grep | wc -l`
        if [ ${processCount} -ne 0 ]
        then
                pid=`ps -aef | grep Session.exe | grep -v grep | awk '{ print $2 }'`
                echo -e "\033[1;20mProcess running with pid \033[1;32m${pid}\033[0m\033[1;20m"
		touch ${SESSION_LAYER_HOME}/stop
                pCount=`ps -aef | grep Session.exe | grep -v grep | awk '{ print $2 }'`
                while [ "$pCount" -lt 1 ]
                do
                        sleep 1
                        pCount=`ps -aef | grep Session.exe | grep -v grep | awk '{ print $2 }'`
                done
        fi
	echo "Session Layer Exited"
}
stopSPS() {
	crontabfile=${SPS_HOME}/crontabfile
	crontabtempfile=${SPS_HOME}/crontabtempfile
	processCrontabCount=`crontab -l 2> /dev/null| grep -w startsps | grep -v grep | wc -l`
	if [ ${processCrontabCount} -ge 1 ]
	then
		`crontab -l 2> /dev/null| grep -v startsps > ${crontabfile}`

                 szFileSize=0
                 szFileSize=`cat ${crontabfile} | wc -l`

                 if [ $szFileSize -ge 1 ]
                 then
                        crontab $crontabfile
                 else
                        crontab -r
                        echo "All crontab entries removed"
                 fi
	fi
	processCount=`ps -aef | grep SPSScheduler | grep -v grep | wc -l`
        if [ ${processCount} -ne 0 ]
        then
                pid=`ps -aef | grep SPSScheduler | grep -v grep | awk '{ print $2 }'`
                echo -e "\033[1;20mProcess running with pid \033[1;32m${pid}\033[0m\033[1;20m"
		kill -s SIGUSR1 ${pid}
		pCount=`ps -aef | grep SPSScheduler | grep -v grep | awk '{ print $2 }'`
		while [ "$pCount" -lt 1 ]
		do
			sleep 1
			pCount=`ps -aef | grep SPSScheduler | grep -v grep | awk '{ print $2 }'`
		done
        fi
	echo "Exited"
}
stop() {
	stopSessionLayer
	stopSPS
		
}
if [ ${flag} -eq 1 ]
then
	start
elif [ ${flag} -eq 2 ]
then
	stop
elif [ ${flag} -eq 3 ]
then
	stop
	start
fi
