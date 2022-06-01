#include <string>
#include "StateMachine.h"


using namespace std;

void StateMachine::run()
{
	int i, j;
	Event curEvent; // 현재 이벤트
	curState = STATE_READY; // 상태 초기화
	while (curState != STATE_END) // EVENT_QUIT이 입력될 때까지 반복 수행함
	{
		curEvent = getNextEvent(); // 다음 이벤트를 입력받음
		if (curEvent == EVENT_QUIT) {
			cout << "프로그램 종료" << endl;
			return;
		}
		for (i = 0; i < NUMBER_OF_TABLE_ENTRIES; i++) // 테이블에 정의된 각 행(transition 내용)에 대해 비교함
		{
			if (curState == table[i].curState) // 현재 상태와 일치하는지 검사
			{
				if (curEvent == table[i].event) // 입력된 현재 이벤트와 일치하는지 검사
				{
					// 해당 transition이 발생할 때 수행해야 할 action 함수들을 실행시킴
					(this->*table[i].action)();
					curState = table[i].nextState; // 테이블에 정의된 다음 상태로 현재 상태를 변경함
					break;
				}
			}
		}
		cout << endl << endl;
	}
}

Event StateMachine::getNextEvent()
{
	Event selectedEvent; // 반환할 이벤트
	int inputEvent; // 사용자로부터 입력받은 이벤트

	// 입력 안내 메세지 출력 및 사용자로부터 입력 받음
	cout << "[현재 상태 : " << getCurrentStateString() << "]" << endl;
	cout << "1. REQUEST_TRIP" << endl;
	cout << "2. REQUEST_PAYMENT" << endl;
	cout << "3. PAYMENT_FAILED" << endl;
	cout << "4. PAYMENT_SUCCEEDED" << endl;
	cout << "5. TRIP_COMPLETED" << endl;
	cout << "6. Quit" << endl;
	cout << "Select an event # : ";
	cin >> inputEvent;

	switch (inputEvent) { // 입력 값에 따라 반환할 이벤트 값을 결정함
	case 1:
		selectedEvent = EVENT_REQUEST_TRIP;
		break;
	case 2:
		selectedEvent = EVENT_REQUEST_PAYMENT;
		break;
	case 3:
		selectedEvent = EVENT_PAYMENT_FAILED;
		break;
	case 4:
		selectedEvent = EVENT_PAYMENT_SUCCEEDED;
		break;
	case 5:
		selectedEvent = EVENT_TRIP_COMPLETED;
		break;
	case 6:
		selectedEvent = EVENT_QUIT;
		break;
	default:
		selectedEvent = EVENT_QUIT;
		curState = STATE_END;
	}

	return selectedEvent;
}


	void StateMachine::requestTrip() { 
		cout << "requestTrip() 불림." << endl;
	}

	void StateMachine::requestPayment() {
		cout << "requestPayment() 불림." << endl;
	}

	void StateMachine::paymentFailed() {
		cout << "paymentFailed() 불림." << endl;
	}

	void StateMachine::paymentSucceeded() {
		cout << "paymentSucceeded() 불림." << endl;
	}

	void StateMachine::tripCompeted() {
		cout << "tripCompeted() 불림." << endl;
	}


	string StateMachine::getCurrentStateString() { // 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
		string returnedString;
		switch (curState) {
		case STATE_READY:
			returnedString = "STATE_READY";
			break;
		case STATE_TRIP_REQUESTED:
			returnedString = "STATE_TRIP_REQUESTED";
			break;
		case STATE_PAYMENT_REQUESTED:
			returnedString = "STATE_PAYMENT_REQUESTED";
			break;
		case STATE_DRIVER_ASSIGNED:
			returnedString = "STATE_DRIVER_ASSIGNED";
		}
		return returnedString;
	}

