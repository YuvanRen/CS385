/*******************************************************************************
* Name : waterjugpuzzle.cpp
* Author : Yuvan Rengifo
* Pledge : I pledge my honor that I have abided by the Stevens Honor System
* Date : April 13, 2023
* Description : Solve water jug problem using BFS
******************************************************************************/
# include <iostream>
# include <sstream>
# include <vector>
# include <queue>
# include <string>
# include <array>
# include <stack>
# include <algorithm>

using namespace std;
int cap_A, cap_B, cap_C;
int goal_A, goal_B, goal_C;
bool found = false;

struct State {
    int a, b, c;
    vector<string> directions;

    State() :
        a{NULL}, b{NULL}, c{NULL}{ }

    State(int _a, int _b, int _c, vector<string> _directions) :
        a{_a}, b{_b}, c{_c}, directions{_directions}{ }

    State(int _a, int _b, int _c) :
        a{_a}, b{_b}, c{_c}{ }

    vector<string> getDirections(){
        return directions;
    }

    void setDirections(vector<string> vec){
        directions = vec;
    }
    // String representation of state in tuple form.
    string to_string( ) {
        ostringstream oss;
        oss << " (" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }

};


int pour(int fromJug, int toJug, int CAP) {
    if(fromJug < 0 || toJug < 0 || CAP <= 0) {
        return -1; // invalid input
    }

    int spaceInToJug = CAP - toJug;
    if(spaceInToJug == 0) {
        return 0; // toJug is already full
    }

    int amountToPour = min(fromJug, spaceInToJug);

    if(amountToPour == 0) {
        return 0; // fromJug is empty or there is no space in toJug
    }

    if(toJug + amountToPour > CAP) {
        return CAP - toJug; // overflow
    }

    return amountToPour;
}

string PourString(string from, string to, int pourAmount){
    string sttr;
    stringstream str;

    if (pourAmount == 1){
        str << "Pour " << pourAmount << " gallon from " << from[0] << " to " << to[0] << ".";
    } else {
        str << "Pour " << pourAmount << " gallons from " << from[0] << " to " << to[0] << ".";
    }
    sttr = str.str();
    return sttr;
}

void BFS(int a, int b, int c) {
    State headState(a, b, c);
    vector<string> beginning;
    beginning.push_back("Initial state. " + headState.to_string());
    headState.setDirections(beginning);

    bool **visited = new bool*[cap_A + 1];
    for(auto i = 0; i < cap_A + 1; i++) {
        visited[i] = new bool[cap_B + 1];
        fill(visited[i], visited[i] + cap_B + 1, false);
    }

    queue<State> q;
    q.push(headState);

    State current;
    bool found = false;
    while (!q.empty()) {
        current = q.front();
        q.pop();

        if(visited[current.a][current.b]){
            continue;
        }

        if(current.a == goal_A && current.b == goal_B){
            found = true;
            break;
        }

        visited[current.a][current.b] = true;
        if((current.c > 0) && (cap_A - current.a >= 0)){
            int pouring = pour(current.c, current.a, cap_A);
            if(!visited[current.a + pouring][current.b]){
                State childstate = State(current.a + pouring, current.b, current.c - pouring);
                vector<string> temp = current.getDirections();
                temp.push_back(PourString("C", "A", pouring) + childstate.to_string());
                childstate.setDirections(temp);
                q.push(childstate);
            }
        }

        // C.B
        if((current.c > 0) && (cap_B - current.b >= 0)){
            int pouring = pour(current.c, current.b, cap_B);
            if(!visited[current.a][current.b + pouring]){
                State childstate = State(current.a, current.b + pouring, current.c - pouring);
                vector<string> temp = current.getDirections();
                temp.push_back(PourString("C", "B", pouring) + childstate.to_string());
                childstate.setDirections(temp);
                q.push(childstate);
            }
        }

        // B.A
        if((current.b > 0) && (cap_A - current.a >= 0)){
                    int pouring = pour(current.b, current.a, cap_A);
                    if(!visited[current.a + pouring][current.b - pouring]){
                        State childstate = State(current.a + pouring, current.b - pouring, current.c);
                        vector<string> temp = current.getDirections();
                        temp.push_back(PourString("B", "A", pouring) + childstate.to_string());
                        childstate.setDirections(temp);
                        q.push(childstate);
                    }
                }

        // B.C
        if((current.b > 0) && (cap_C - current.c >= 0)){
            int pouring = pour(current.b, current.c, cap_C);
            if(!visited[current.a][current.b - pouring]){
                State childstate = State(current.a, current.b - pouring, current.c + pouring);
                vector<string> temp = current.getDirections();
                temp.push_back(PourString("B", "C", pouring) +childstate.to_string());
                childstate.setDirections(temp);
                q.push(childstate);
            }
        }

        // A.B
        if((current.a > 0) && (cap_B - current.b >= 0)){
            int pouring = pour(current.a, current.b, cap_B);
            if(!visited[current.a - pouring][current.b + pouring]){
                State childstate = State(current.a - pouring, current.b + pouring, current.c);
                vector<string> temp = current.getDirections();
                temp.push_back(PourString("A", "B", pouring) + childstate.to_string());
                childstate.setDirections(temp);
                q.push(childstate);
            }
        }

        // A.C
        if((current.a > 0) && (cap_C - current.c >= 0)){
            int pouring = pour(current.a, current.c, cap_C);
            if(!visited[current.a - pouring][current.b]){
                State childstate = State(current.a - pouring, current.b, current.c + pouring);
                vector<string> temp = current.getDirections();
                temp.push_back(PourString("A", "C", pouring) + childstate.to_string());
                childstate.setDirections(temp);
                q.push(childstate);
            }
        }
    }
    if(found){
        vector<string> vec = current.getDirections();
        for(unsigned int i = 0; i < vec.size(); i++){
            cout << vec[i] << endl;
        }
    } else {
        cout << "No solution." << endl;
    }

    for (int i = 0; i <= cap_A; ++i) {
        delete[] visited[i];
    }
    delete[] visited;
}



int main(int argc, char* argv[]){
    int temp, max;
    int sum = 0;

    char jugs[] =  { 'A', 'B', 'C', 'A', 'B', 'C', '\0' };
    if (argc != 7){
        cerr << "Usage: " << argv[0] << " <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
        return 1;
    }

    for(int i = 1; i <= 6; i++){
        istringstream iss;
        iss.str(argv[i]);
        if(!(iss >> temp) or (temp < 0)){
            if (i <= 3){
                cerr << "Error: Invalid capacity '" << argv[i] << "' for jug " << jugs[i-1] <<  "." << endl;
                return 1;
            } else {
                cerr << "Error: Invalid goal '" << argv[i] << "' for jug " << jugs[i-1] <<  "." << endl;
                return 1;
            }
        }

        if ((i == 3) && (temp == 0)){
            cerr << "Error: Invalid capacity '" << argv[i] << "' for jug " << jugs[i-1] <<  "." << endl;
            return 1;
        }

        if (i == 3){
            max = temp;
        }
        else if (i > 3){
            sum += temp;
        }
        iss.clear();
    }


    int tempCap, tempGoal;
    for(int i = 1; i <= 3; i++){
        istringstream cap(argv[i]);
        cap >> tempCap;
        istringstream goal(argv[i+3]);
        goal >> tempGoal;

        if ((tempGoal > tempCap)) {
            cerr << "Error: Goal cannot exceed capacity of jug " << jugs[i-1] <<  "." << endl;
            return 1;
        }
    }

    if (sum != max) {
        cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
        return 1;
    }


    istringstream capA(argv[1]);
    capA >> cap_A;

    istringstream capB(argv[2]);
    capB >> cap_B;

    istringstream capC(argv[3]);
    capC >> cap_C;

    istringstream goalA(argv[4]);
    goalA >> goal_A;

    istringstream goalB(argv[5]);
    goalB >> goal_B;

    istringstream goalC(argv[6]);
    goalC >> goal_C;

    BFS(0,0, cap_C);
    return 0;

}
