
all:	controller addRecord deleteRecord

controller:	controller.cpp Record.h
	g++ -O3 controller.cpp -o controller

addRecord:	addRecord.cpp Record.h
	g++ -O3 addRecord.cpp -o addRecord

deleteRecord:	deleteRecord.cpp Record.h
	g++ -O3 deleteRecord.cpp -o deleteRecord

clean:
	rm controller addRecord deleteRecord
