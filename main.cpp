#include <iostream>
#include "heap.h"
#include <string>
#include <cstdlib>
using namespace std;

void test(){

}

int main()
{
//    test();
    heap h;
    h.insert(28);
    h.insert(29);
    h.insert(30);
    h.insert(9);
    h.remove(28);
    int q = 0;
    string input, next;
    string delimit = " ";
    cout << 1/2;
    while(q == 0){

        cout << "prompt> ";
        getline(cin, input);
        if(input.substr(0, input.find(delimit)).compare("ins") == 0){
            if(!(input.length() < 5)){
                next = input.substr(input.find(delimit) + 1, input.length()-1);
                int val = atoi(next.substr(0, next.find(delimit)).c_str());
//                cout << val << endl;
                if(val <= 0){
                    cout << "ERROR: Input is invalid"<< endl;
                }
                else{
//                    if(binary.find(val) == 0){
//                        cout << "ERROR: " << val << " is already added" << endl;
//                    }
//                    else{
////                        binary.insert(val);
//                        cout << val << " added" << endl;
//                    }
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }
        else if(input.substr(0, input.find(delimit)).compare("rm") == 0){
            if(!(input.length() < 4)){
                next = input.substr(input.find(delimit) + 1, input.length()-1);
                int val = atoi(next.substr(0, next.find(delimit)).c_str());
//                cout << val << endl;
                if(val <= 0){
                    cout << "ERROR: Input is invalid" << endl;
                }
                else{
//                    if(binary.find(val) == 0){
////                        binary.remove(val);
//                        cout << val << " is removed" << endl;
//                    }
//                    else if(binary.find(val) == -2){
//                        cout << "ERROR: Tree is empty" << endl;
//                    }
//                    else{
//                        cout << "ERROR: "<< val << " is not found" << endl;
//                    }
                }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }
        else if(input.substr(0, input.find(delimit)).compare("levelo") == 0){
            if((input.length() < 7)){
//                    if(binary.find(0) == -2){
//                        cout << "ERROR: Tree is empty" << endl;
//                    }
//                    else{
//                        cout << "LevelOrder Traversal" << endl;
//                        cout << "   ";
                        h.levelOrder();
//                        cout << endl;
//                    }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("max") == 0){
            if((input.length() < 4)){
                    if(h.maximum() == -1){
                        cout << "ERROR: Tree is empty" << endl;
                    }
                    else{
                        cout << "Maximum: " << h.maximum() << endl;
                        }
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }

        else if(input.substr(0, input.find(delimit)).compare("bye") == 0){
            if((input.length() < 4)){
                    return 0;
            }
            else
                cout << "ERROR: Input is invalid" << endl;
        }


        else{
            cout << "ERROR: Invalid Command" << endl;
        }

    }
    return 0;
}
