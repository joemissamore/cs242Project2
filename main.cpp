#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {


    ifstream input;
    input.open("toy.data.txt");

    string inputString;

    vector<vector<int>> values;

    vector<int> pb;

    int num;

    while (!input.eof()) {
        getline(input, inputString);
        stringstream iss(inputString);

        while (iss >> num) {
            pb.push_back(num);
        }

        values.push_back(pb);
        pb.clear();
    }



    // Import toy.class.txt
    ifstream toyClass;
    toyClass.open("toy.class.txt");

    vector<int> classToy;

    if (toyClass)
    {
        int numClass;

        while (toyClass >> numClass)
        {
            classToy.push_back(numClass);
        }

    }

    int sC = 0;
    int iC = 0;

    for (int i = 0; i < classToy.size(); i++)
    {
        if (classToy[i] == 1)
        {
            sC++;
        }
        else
        {
                iC++;
        }
        cout << classToy[i] << endl;

    }

    cout << "sC: " << sC << endl;
    cout << "iC: " << iC << endl;

    // Calculating sets
    double totalSets = iC + sC;

    // P(i)
    double pOfI = iC / totalSets;

    // P(s)
    double pOfS = sC / totalSets;

    return 0;

}