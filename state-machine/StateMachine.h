#pragma once
#include <iostream>


#define NUMBER_OF_TABLE_ENTRIES 100 // event-action table�� ���� entry ����

using namespace std;

// State ������ ����
typedef enum {
	STATE_READY,
	STATE_TRIP_REQUESTED,
	STATE_PAYMENT_REQUESTED,
	STATE_DRIVER_ASSIGNED,
	STATE_END
} State;

// Event ������ ����
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
	State curState; // ���� ����
	typedef struct { // event-action table structure ����
		State curState; // ���� ����
		Event event; // ����ڷκ��͹߻��� �̺�Ʈ
		void (StateMachine::* action)(); // action �Լ� ������
		State nextState; // transition �Ŀ� ����� ���� ����
	} EventActionTable;

	EventActionTable table[NUMBER_OF_TABLE_ENTRIES]{ // vending machine���� ����� event-action table �ʱ�ȭ
	{STATE_READY, EVENT_REQUEST_TRIP, &StateMachine::requestTrip, STATE_TRIP_REQUESTED},
	{STATE_TRIP_REQUESTED, EVENT_REQUEST_PAYMENT, &StateMachine::requestPayment, STATE_PAYMENT_REQUESTED},
	{STATE_PAYMENT_REQUESTED, EVENT_PAYMENT_FAILED, &StateMachine::paymentFailed, STATE_TRIP_REQUESTED},
	{STATE_PAYMENT_REQUESTED, EVENT_PAYMENT_SUCCEEDED, &StateMachine::paymentSucceeded, STATE_DRIVER_ASSIGNED},
	{STATE_DRIVER_ASSIGNED, EVENT_TRIP_COMPLETED, &StateMachine::tripCompeted, STATE_READY},
	};

	void requestTrip(); // LED ȭ�鿡 ���� ���Ե� �ݾ��� ǥ����
	void requestPayment(); // ��ȯ ��ư�� ������ �� ���Ե� �ݾ��� ��ȯ��
	void paymentFailed(); // ���� ��ư�� ������ �Ѱų� ���� ���� ������ -> on = 1, off = 0;
	void paymentSucceeded(); // ������ ���Ḧ �ܺη� ������ -> dummy parameter
	void tripCompeted();

	Event getNextEvent(); // ����ڷκ��� ���� �̺�Ʈ�� �Է¹���
	string getCurrentStateString(); // ���� ���¿� �ش��ϴ� ���ڿ��� �����ؼ� ��ȯ��

public:
	void run();
};