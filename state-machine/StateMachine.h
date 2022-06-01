#pragma once
#include <iostream>


#define NUMBER_OF_TABLE_ENTRIES 100 // event-action table의 현재 entry 갯수

using namespace std;

// State 열거형 정의
typedef enum {
	STATE_READY,
	STATE_TRIP_REQUESTED,
	STATE_PAYMENT_REQUESTED,
	STATE_DRIVER_ASSIGNED,
	STATE_END
} State;

// Event 열거형 정의
typedef enum {
	EVENT_REQUEST_TRIP,
	EVENT_REQUEST_PAYMENT,
	EVENT_PAYMENT_FAILED,
	EVENT_PAYMENT_SUCCEEDED,
	EVENT_TRIP_COMPLETED,
	EVENT_QUIT
} Event;

class StateMachine {
private:
	State curState; // 현재 상태
	typedef struct { // event-action table structure 정의
		State curState; // 현재 상태
		Event event; // 사용자로부터발생된 이벤트
		void (StateMachine::* action)(); // action 함수 포인터
		State nextState; // transition 후에 변경될 다음 상태
	} EventActionTable;

	EventActionTable table[NUMBER_OF_TABLE_ENTRIES]{ // vending machine에서 사용할 event-action table 초기화
	{STATE_READY, EVENT_REQUEST_TRIP, &StateMachine::requestTrip, STATE_TRIP_REQUESTED},
	{STATE_TRIP_REQUESTED, EVENT_REQUEST_PAYMENT, &StateMachine::requestPayment, STATE_PAYMENT_REQUESTED},
	{STATE_PAYMENT_REQUESTED, EVENT_PAYMENT_FAILED, &StateMachine::paymentFailed, STATE_TRIP_REQUESTED},
	{STATE_PAYMENT_REQUESTED, EVENT_PAYMENT_SUCCEEDED, &StateMachine::paymentSucceeded, STATE_DRIVER_ASSIGNED},
	{STATE_DRIVER_ASSIGNED, EVENT_TRIP_COMPLETED, &StateMachine::tripCompeted, STATE_READY},
	};

	void requestTrip(); // LED 화면에 현재 투입된 금액을 표시함
	void requestPayment(); // 반환 버튼을 눌렀을 때 투입된 금액을 반환함
	void paymentFailed(); // 음료 버튼에 조명을 켜거나 끄는 동작 수행함 -> on = 1, off = 0;
	void paymentSucceeded(); // 선택한 음료를 외부로 내보냄 -> dummy parameter
	void tripCompeted();

	Event getNextEvent(); // 사용자로부터 다음 이벤트를 입력받음
	string getCurrentStateString(); // 현재 상태에 해당하는 문자열을 생성해서 반환함

public:
	void run();
};