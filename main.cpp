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

    int pbSize;

    while (!input.eof()) {
        getline(input, inputString);
        stringstream iss(inputString);

        while (iss >> num) {
            pb.push_back(num);
        }

        values.push_back(pb);
        pbSize = pb.size();
        pb.clear();
    }
    input.close();



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
    // Counting Words
    int countWordS[pbSize];
    int countWordI [pbSize];

    // Calculating probability
    double probWordS[pbSize];
    double probWordI[pbSize];

    // Initalize Arrays
    for (int i = 0; i < pbSize; i++)
    {
        countWordS[i] = 0;
        countWordI[i] = 0;

        probWordS[i] = 0;
        probWordI[i] = 0;
    }

    double sC = 0;
    double iC = 0;

    for (int i = 0; i < classToy.size(); i++)
    {
        if (classToy[i] == 1)
        {
            for (int j = 0; j < values[i].size(); j++)
            {
                if (values[i][j] == 1)
                {
                    countWordS[j]++;
                }
            }
            sC++;
        }
        else
        {
            for (int j = 0; j < values[i].size(); j++)
            {
                if (values[i][j] == 1)
                {
                    countWordI[j]++;
                }
            }
                iC++;
        }
//        cout << "classToy: " << classToy[i] << endl;



    }

    // Calculating sets
    double totalSets = iC + sC;

    // P(i)
    double pOfI = iC / totalSets;

    // P(s)
    double pOfS = sC / totalSets;

    // Calculating P(Wsubset(t) | C = S)
    for (int i = 0; i < pbSize; i++)
    {
        // # of times the wt was observed
        probWordS[i] = countWordS[i] / sC;
        probWordI[i] = countWordI[i] / iC;
    }





    // Start input data
    ifstream inputTestData;
    inputTestData.open("toytest.data.txt");

    vector<vector<int>> testData;
    vector<int> pbTestData;
    string testDataString;
    int testDataInt;

    int testDataSize;

    while (!inputTestData.eof()) {
        getline(inputTestData, testDataString);
        stringstream issT(testDataString);

        while (issT >> testDataInt) {
            pbTestData.push_back(testDataInt);
        }

        testDataSize = pbTestData.size();
        testData.push_back(pbTestData);
        pbTestData.clear();
    }
    inputTestData.close();


    int testDataCount[testDataSize];
    double calcTestData[testData.size()][testDataSize];
    double pBarS [testData.size()];
    double pBarI [testData.size()];

    // Initialize testDataCount
    for (int i = 0; i < testDataSize; i++)
    {
        testDataCount[i] = 0;
    }

    // Initialize pBars
    for (int i = 0; i < testData.size(); i++)
    {
        pBarS[i] = 1;
        pBarI[i] = 1;
    }


    // Loop through and see if wt is present
    // Loops through outter part of Vector
    for (int i = 0; i < testData.size(); i++)
    {
        // Loop through inner part of vector
        for (int j = 0; j < testData[i].size(); j++)
        {
            if (testData[i][j] == 1)
            {
                calcTestData[i][j] = probWordS[j];
            }
            else
            {
                calcTestData[i][j] = 1 - probWordS[j] ;
            }


        }

    }

    for (int i = 0; i < testData.size(); i++)
    {
            for (int j = 0; j < testDataSize; j++)
            {
                pBarS[i] *= calcTestData[i][j];
                pBarI[i] *= calcTestData[i][j];
            }
            pBarS[i] *= pOfS;
            pBarI[i] *= pOfI;
    }






    // DEBUG
    cout << "\n \n";
    cout << "sC: " << sC << endl;
    cout << "iC: " << iC << endl;


    cout << "\n \n";

    for (int i = 0; i < pbSize; i++)
    {
        cout << "countWordS" << "[" << i  << "]: " << "[" << countWordS[i] << "]" << endl;

    }

    cout << "\n \n";

    for (int i = 0; i < pbSize; i++)
    {
        cout << "countWordI" << "[" << i  << "]: " << "[" << countWordI[i] << "]" << endl;
    }

    cout << "\n \n";

    for (int i = 0; i < pbSize; i++)
    {
        cout << "probWordsS[" << i << "]: " << probWordS[i] << endl;
    }

    cout << "\n \n";

    for (int i = 0; i < pbSize; i++)
    {
        cout << "probWordsI[" << i << "]: " << probWordI[i] << endl;
    }


    cout << "\n \n";


    for (int i = 0; i < testData.size(); i++)
    {
        for (int j = 0; j < testData[i].size(); j++)
        {
            cout << "testData[" << i << "]" << "[" << j << "]: " << testData[i][j] << endl;
        }
    }

    cout << "\n \n";


    for (int i = 0; i < testDataSize; i++)
    {
        cout << "testDataCount[" << i << "]: " << testDataCount[i] << endl;
    }


    cout << "\n \n";


    // Loop through and see if wt is present
    // Loops through outter part of Vector
    for (int i = 0; i < testData.size(); i++)
    {
        // Loop through inner part of vector
        for (int j = 0; j < testData[i].size(); j++)
        {

                cout << "calcTestData" << "[" << i << "]" << "[" << j << "]" << calcTestData[i][j] << endl;
        }

    }

    cout << "\n \n";

    cout << "testData.size(): " << testData.size();


    cout << "\n \n";

    for (int i = 0; i < testData.size(); i++)
    {
        cout << "pBarS[" << i << "]: " << pBarS[i] << endl;
    }

    cout << "\n \n";

    for (int i = 0; i < testData.size(); i++)
    {
        cout << "pBarI[" << i << "]: " << pBarI[i] << endl;
    }

    return 0;

}