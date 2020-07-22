#include <iostream>
#include "Heap_PriorityQueue.h"
using namespace std;

void processNextPatient(PatientQueue *queue);

int main()
{
	PatientQueue *queue = new PatientQueue();
	queue->enqueue(22, "Lila");
	processNextPatient(queue);
	queue->printList();

	processNextPatient(queue);

	queue->enqueue(3, "Liz");
	queue->enqueue(19, "Xylo");
	queue->enqueue(20, "Zedder");
	queue->enqueue(15, "Ratner");
	queue->enqueue(7, "Tattle");
	queue->enqueue(6, "Sassy");
	queue->enqueue(2, "Elle");
	queue->enqueue(1, "Alph");
	queue->enqueue(5, "Ophra");
	queue->enqueue(4, "Mommy");

	processNextPatient(queue);

	cout << queue->size() << " patient" << (queue->size() == 1 ? "" : "s") << " currently waiting." << endl;

	queue->enqueue(1, "Aso");
	queue->enqueue(8, "Vinnie");

	delete queue;

	return 0;
}

void processNextPatient(PatientQueue *queue)
{
	if (queue == NULL)
	{
		cout << "No one waiting!" << endl;
	}
	else if (!queue->isEmpty())
	{
		Patient *next = queue->dequeue();
		cout << "===\nNEXT! - " << next->name << endl;
		delete next;
	}
}