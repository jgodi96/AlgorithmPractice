#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct{
    int landingTimeBST;
    string* flightNumber;
    allFlights* next;
}allFlights;

int main() {

    cout << "Enter the K value" << std::endl;
    int K;
    cin >> K;

    allFlights *head = NULL;

    cout << "Enter option which you want to perform" << endl;
    cout << "(R/r) Request Landing" << endl;
    cout << "(W/w) Withdraw Landing Request" << endl;
    cout << "(L/l) List landing times and flight number" << endl;
    cout << "(Q/q) Quit" << endl;

    char userOption;

    cin >> userOption;

    while (true){
        if(userOption == 'R' || userOption == 'r'){
            if(head == NULL){

                cout << "Enter Landing Time BST : ";
                cin >> head->landingTimeBST;
                if(head->landingTimeBST >= K){
                    cout << "Enter Flight Number : ";
                    head->flightNumber = new string;
                    cin >> *head->flightNumber;
                    cout << "Done" << endl;
                    head->next = NULL;
                }else{
                    cout << "Does not satisfies the K constraint" << endl;
                    delete(head);
                    cout << "Try again" << endl;
                }
            }else{
                allFlights *nextFlight = head;
                while (nextFlight->next != NULL){
                    nextFlight = nextFlight->next;
                }
    

                cout << "Enter Landing Time BST : ";
                cin >> newFlight->landingTimeBST;
                bool isInserted = false;


                if(head->landingTimeBST - newFlight->landingTimeBST >= K && newFlight->landingTimeBST >= K){

                    cout << "Enter Flight Number : ";
                    head->flightNumber = new string;
                    cin >> *head->flightNumber;
                    newFlight->next = head;
                    head = newFlight;
                    isInserted = true;

                }else if(newFlight->landingTimeBST - nextFlight->landingTimeBST >= K){

                    cout << "Enter Flight Number : ";
                    head->flightNumber = new string;
                    cin >> *head->flightNumber;
                    newFlight->next = NULL;
                    nextFlight->next = newFlight;
                    isInserted = true;

                }else{

                    allFlights *prev = head;
                    nextFlight = head->next;

                    while (nextFlight != NULL){

                        if(newFlight->landingTimeBST - prev->landingTimeBST >= K && nextFlight->landingTimeBST - newFlight->landingTimeBST >= K){

                            cout << "Enter Flight Number : ";
                            head->flightNumber = new string;
                            cin >> *head->flightNumber;
                            prev->next = newFlight;
                            newFlight->next = nextFlight;
                            isInserted = true;
                            break;

                        }

                        nextFlight = newFlight->next;
                        prev = prev->next;

                    }

                    if(!isInserted){
                        cout << "Does not satisfies the K constraint" << endl;
                        free(newFlight);
                        cout << "Try again" << endl;
                    }


                }
            }
        }else if(userOption == 'W' || userOption == 'w'){
            allFlights *prevFlight = head;
            allFlights *nextFlight = head->next;
            cout << "Enter Flight Landing Time BST to Withdraw" << endl;
            int landingTimeBST;
            cin >> landingTimeBST;

            if(head->landingTimeBST == landingTimeBST){
                head = head->next;
                free(prevFlight);
            }else{
                bool isWithdrawn = false;
                while(nextFlight != NULL){
                    if(nextFlight->landingTimeBST == landingTimeBST){
                        prevFlight->next = nextFlight->next;
                        free(nextFlight);
                        isWithdrawn = true;
                        break;

                    }
                    prevFlight = prevFlight->next;
                    nextFlight = nextFlight->next;
                }
                if(!isWithdrawn){
                    cout << "Error! Landing Time BST not found" << endl;
                    cout << "Try again";
                }
            }

        }else if(userOption == 'L' || userOption == 'l'){
            allFlights *nextFlight = head;
            if(nextFlight == NULL){
                cout << "No Flights!" << endl;
            } else{
                while(nextFlight != NULL){
                    cout << "Flight Number : " << *nextFlight->flightNumber << " Landing Time BST : " << nextFlight->landingTimeBST << endl;
                    nextFlight = nextFlight->next;
                }
            }
        }else if(userOption == 'Q' || userOption == 'q'){
            break;
        }else{
            cout << "Wrong input! Please Try again" << endl;
        }

        cout << "Enter option which you want to perform from above choices" << endl;
        cin >> userOption;
    }


    return 0;
}
