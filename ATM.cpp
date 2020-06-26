#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <time.h>

using namespace std;

void menu(void)
{
    //here is the menu
    cout<<" 1 - 50 RON                   4 - 300 RON"<<endl;
    cout<<" 2 - 100 RON                  5 - 500 RON"<<endl;
    cout<<" 3 - 150 RON                  6 - Another amount "<<endl;

}

const std::string currentdataTime()
{   //the function return current time
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d  %X", &tstruct);

    return buf;
}
void receipt(float sold, char transactions[20][100], int nr_trans)
{   //this function creates the receipt
    cout<<endl<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"*************    Transilvania Bank   *****************|"<<endl;
    cout<<"***********    ATM cod 217, adress x    **************|"<<endl;
    cout<<"                                                      |"<<endl;
    cout<<"                                                      |"<<endl;
    cout<<" The following were performed:                        |"<<endl;
    cout<<"                                                      |"<<endl;
    int i = 1;
    while(i <= nr_trans)
    {
        if( strcmp(transactions[i],"Interrogate sold") == 0)
            cout<<"               "<<i<<" - "<<transactions[i]<<"                   |"<<endl;
        if( strcmp(transactions[i],"Cash withdrawal") == 0)
            cout<<"               "<<i<<" - "<<transactions[i]<<"                    |"<<endl;
        if( strcmp(transactions[i],"Cash deposit") == 0)
            cout<<"               "<<i<<" - "<<transactions[i]<<"                       |"<<endl;
        i++;
    }
    cout<<"                                                      |"<<endl;
    cout<<"                                                      |"<<endl;
    cout<<"------------       Sold: "<<sold<<"      -----------------|"<<endl;
    cout<<"                                                      |"<<endl;
    cout<<"                                                      |"<<endl;
    cout<<"*********    Date: "<<currentdataTime()<<"     **********|"<<endl;
    cout<<"*************        Thank you!"<<"       ****************|"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<endl<<endl<<endl<<endl;

}

int main()
{   char language, data[100], transactions[20][100];
    int pin, correct_pin, attemps = 0, option, contor = 0, ans, sum, nr_trans = 0, key, i;
    float sold;


    fstream file("file.txt");


// I read the data about the client (we assume that the card has been inserted into the atm :D)
    contor = 0;
    while(contor != 4){

        contor++;
        file.getline(data,100);
        if(contor == 3)
            correct_pin = atoi(data);
    }



    cout <<"             Welcome!" << endl<<endl;
    Sleep(2000);
    cout <<"       Choose one of the languages:" << endl<<endl;
    cout<<" 1-> Romanian                          2-> English"<<endl;//here can be added any language
    cin>>language;
    cout<<" Enter the pin: ";

 // here is the part of verify the card pin
 //if you type wrong 3 times , the card will be blocked
    while(pin != correct_pin && attemps < 3){

        cin>>pin;
        Sleep(2000);

        if(pin == correct_pin){
            break;
        }
        else{
            if(attemps < 2){cout<<" Incorrect pin! Try again! "<<endl;}
        }

        attemps++;
        if(attemps == 3){ cout<<" Card blocked! Please contact the card issuer for issuance! "<<endl; return 0;}

    }



 //here i transform "the sold" from string to float
    char aux[40];
    contor = 0;
    for(i = 6; i < strlen(data); i++){
       aux[contor] = data[i];
       contor++;
    }

    aux[contor] = '\0';
    sold = atof(aux);


    while(1){

        cout<<endl;
        cout<<" 1 - Interrogate sold                    2 - Cash withdrawal "<<endl;
        cout<<" 3 - Cash deposit                        4 - Exit "<<endl;
        cin>>option;
        nr_trans++;


        if(option == 1){

            Sleep(1500);
            strcpy(transactions[nr_trans],"Interrogate sold");
            cout<<endl<<" Sold: "<<sold<<endl;
            cout<<endl<<" Do you want to make another transaction? "<<endl;
            cout<<" 1 - YES                      2 - NO  "<<endl;
            cin>>ans;
            if(ans == 2){

                cout<<"             Thank you!"<<endl;
                Sleep(2000);
                break;
            }
        }


        if(option == 2){

            strcpy(transactions[nr_trans],"Cash withdrawal");
            menu();
            cin>>key;
            switch(key){ //i used switch for all cases of cash withdrawal
                case 1:
                    if(sold >= 50){

                        sold -= 50;
                        cout<<" Do you want the receipt?"<<endl;
                        cout<<" 1 - YES                      2 - NO  "<<endl;
                        cin>>ans;
                        if(ans == 1)
                            receipt(sold,transactions,nr_trans);
                    }
                    else{

                        cout<<endl<<" Insufficient funds! "<<endl;
                        break;
                    }

                break;

                case 2:
                     if(sold >= 100){

                        sold -= 100;
                        cout<<"Do you want the receipt?"<<endl;
                        cout<<" 1 - YES                      2 - NO  "<<endl;
                        cin>>ans;
                        if(ans == 1)
                            receipt(sold,transactions,nr_trans);
                     }
                     else{

                        cout<<" Insufficient funds!  "<<endl;
                        break;
                     }

                break;

                case 3:
                     if(sold >= 150){

                        sold -= 150;
                        cout<<" Do you want the receipt?"<<endl;
                        cout<<" 1 - YES                      2 - NO  "<<endl;
                        cin>>ans;
                        if(ans == 1)
                            receipt(sold,transactions,nr_trans);
                     }
                    else{

                        cout<<" Insufficient funds!  "<<endl;
                        break;
                    }

                break;

                case 4:
                     if(sold >= 300){

                        sold -= 300;
                        cout<<" Do you want the receipt?"<<endl;
                        cout<<" 1 - YES                      2 - NO  "<<endl;
                        cin>>ans;
                        if(ans == 1)
                            receipt(sold,transactions,nr_trans);
                     }
                    else{

                        cout<<" Insufficient funds!  "<<endl;
                        break;
                    }

                break;

                case 5:
                     if(sold >= 500){

                        sold -= 500;
                        cout<<" Do you want the receipt?"<<endl;
                        cout<<" 1 - YES                      2 - NO  "<<endl;
                        cin>>ans;
                        if(ans == 1)
                            receipt(sold,transactions,nr_trans);
                     }
                    else{

                        cout<<" Insufficient funds!  "<<endl;
                        break;
                    }

                break;

                case 6:
                    cout<<" Enter the amount you want to withdraw: ";
                    cin>>sum;
                    if(sold >= sum){

                        sold -= sum;
                        cout<<" Do you want the receipt?"<<endl;
                        cout<<" 1 - YES                      2 - NO  "<<endl;
                        cin>>ans;
                        if(ans == 1)
                            receipt(sold,transactions,nr_trans);
                    }
                    else{

                        cout<<" Insufficient funds!  "<<endl;
                        break;
                    }

                break;

            }

        }


        if(option == 3){

            strcpy(transactions[nr_trans],"Cash deposit");
            cout<<" Place the banknotes in the indicated area "<<endl;
            Sleep(1500);
            cout<<" The amount deposited: "; // here is just an example, in reality the process is automatic
            cin>>sum;
            sold += sum;
            cout<<" Do you want the receipt?"<<endl;
            cout<<" 1 - YES                      2 - NO  "<<endl;
            cin>>ans;
            if(ans == 1)
                receipt(sold,transactions,nr_trans);
        }


        if(option == 4){

            cout<<"                     Thank you! "<<endl;
            Sleep(2000);
            break;
        }
    }


    //this part modifies input file, "the sold" of client.
    file.seekg(0);
    contor = 0;
    while(contor != 3){

        contor++;
        file.getline(data, 100);
    }

    file << "Sold: ";
    file << sold;


    file.close();




    return 0;
}
