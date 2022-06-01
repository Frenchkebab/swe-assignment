#include <string>
#include "StateMachine.h"


using namespace std;

void StateMachine::run()
{
	int i, j;
	Event curEvent; // ���� �̺�Ʈ
	curState = STATE_READY; // ���� �ʱ�ȭ
	while (curState != STATE_END) // EVENT_QUIT�� �Էµ� ������ �ݺ� ������
	{
		curEvent = getNextEvent(); // ���� �̺�Ʈ�� �Է¹���
		if (curEvent == EVENT_QUIT) {
			cout << "���α׷� ����" << endl;
			return;
		}
		for (i = 0; i < NUMBER_OF_TABLE_ENTRIES; i++) // ���̺� ���ǵ� �� ��(transition ����)�� ���� ����
		{
			if (curState == table[i].curState) // ���� ���¿� ��ġ�ϴ��� �˻�
			{
				if (curEvent == table[i].event) // �Էµ� ���� �̺�Ʈ�� ��ġ�ϴ��� �˻�
				{
					// �ش� transition�� �߻��� �� �����ؾ� �� action �Լ����� �����Ŵ
					(this->*table[i].action)();
					curState = table[i].nextState; // ���̺� ���ǵ� ���� ���·� ���� ���¸� ������
					break;
				}
			}
		}
		cout << endl << endl;
	}
}

Event StateMachine::getNextEvent()
{
	Event selectedEvent; // ��ȯ�� �̺�Ʈ
	int inputEvent; // ����ڷκ��� �Է¹��� �̺�Ʈ

	// �Է� �ȳ� �޼��� ��� �� ����ڷκ��� �Է� ����
	cout << "[���� ���� : " << getCurrentStateString() << "]" << endl;
	cout << "1. REQUEST_TRIP" << endl;
	cout << "2. REQUEST_PAYMENT" << endl;
	cout << "3. PAYMENT_FAILED" << endl;
	cout << "4. PAYMENT_SUCCEEDED" << endl;
	cout << "5. TRIP_COMPLETED" << endl;
	cout << "6. Quit" << endl;
	cout << "Select an event # : ";
	cin >> inputEvent;

	switch (inputEvent) { // �Է� ���� ���� ��ȯ�� �̺�Ʈ ���� ������
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
		cout << "requestTrip() �Ҹ�." << endl;
	}

	void StateMachine::requestPayment() {
		cout << "requestPayment() �Ҹ�." << endl;
	}

	void StateMachine::paymentFailed() {
		cout << "paymentFailed() �Ҹ�." << endl;
	}

	void StateMachine::paymentSucceeded() {
		cout << "paymentSucceeded() �Ҹ�." << endl;
	}

	void StateMachine::tripCompeted() {
		cout << "tripCompeted() �Ҹ�." << endl;
	}


	string StateMachine::getCurrentStateString() { // ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
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

