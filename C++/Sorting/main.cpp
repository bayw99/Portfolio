/*
 Final
 By Bailey Williams
 12/8/19
 Program finds and compares the average running time for various common sorting and search algorithms with the following requirements at a minimum.
 */

#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
using namespace std::chrono;

const int bound = 100000;
const int maxnum = 100000;
int numcopies, numcompares;

void randNumGenerator()
{
    int i = 0, num;
    double temp = 0.0;
    float pi = 3.14159265359;
    ofstream otf("input.txt");
    otf.precision(8);
    while(i < maxnum)
    {
        num = rand() + 0.2946382070;
        temp = (num + pi)*pow(-1.0, i);
        if(i != 0)
            temp = temp/(pow(i, 2));
        temp = temp * pi * 10;
        if(abs(temp) < bound)
        {
            otf << setw(15) << temp << endl;
            i++;
        }
    }
    otf.close();
}
void swapem(double &a, double &b)
{
    double temp;
    temp = a;
    a = b;
    b = temp;
    numcopies += 3;
}

void improvedBubblesort(double s[])
{
    int n = maxnum;
    bool sorted = false;
    int i = 0;
    while (!sorted)
    {
        sorted = true;
        for(int j = 0; j < n-1-i;j++)
        {
            numcompares += 1;
            if(s[j] > s[j+1])
            {
                swapem(s[j], s[j+1]);
                sorted = false;
            }
        }
        i++;
    }
}

void bubblesort(double s[])
{
    int n = maxnum;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            numcompares +=1;
            if(s[j] > s[j+1]) swapem(s[j], s[j+1]);
        }
    }
}

void selectsort(double s[])
{
    int n = maxnum;
    if(n > 1)
    {
        for(int k = 0; k < n-1; k++)
        {
            int small = k;
            for(int j = k+1; j < n; j++)
            {
                numcompares += 1;
                if(s[j] < s[small]) small = j;
            }
            if( k != small) swapem(s[k], s[small]);
        }
    }
}

void insertsort(double s[])
{
    int n = maxnum;
    for( int k = maxnum-2; k >= 0; k--)
    {
        int j = k+1;
        double save = s[k];
        s[n] = save;
        numcopies += 2;
        numcompares++;
        while(save > s[j])
        {
            numcompares++;
            s[j-1] = s[j];
            numcopies++;
            j = j+1;
        }
        s[j-1] = save;
        numcopies++;
    }
}

void shellsort(double arr[], int n)
{
     for (int gap = n / 2; gap > 0; gap /= 2)
     {
         for (int i = gap; i < n; i += 1)
         {
             int temp = arr[i];
             numcopies++;
             int j;
             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
             {
                 arr[j] = arr[j - gap];
                 numcompares += 2;
             }
             arr[j] = temp;
             numcopies++;
         }
     }
}

void quicksort(double s[], int l, int r)
{
    if(l < r)
    {
        int j = l;
        int k = r+1;
        do
        {
            do
            {
                j++;
                numcompares++;
            }while(j <= k && s[j] < s[l]);
            do
            {
                k--;
                numcompares++;
            }while(k > l && s[k] > s[l]);
            if(j < k) swapem(s[j], s[k]);
        }while(j <= k);
        swapem(s[l], s[k]);
        quicksort(s, l, k-1);
        quicksort(s, k+1, r);
    }
}

void merge(double arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    numcopies +=2;
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        numcopies++;
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        numcopies++;
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        numcompares += 2;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            numcompares++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        numcompares++;
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        numcompares++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(double arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void heapify(double arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    numcopies += 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
        numcopies++;
        numcompares++;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
         numcopies++;
        numcompares += 2;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(double arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void readem(double s[])
{
    int incr = 1;
    ifstream inf("input.txt");
    if(!inf) cout << "Cannot open file." << endl;
    else
    {
        for(int i = 0; i < maxnum+1; i+= incr)
        {
            inf >> s[i];
        }
    }
}
void printem(ofstream &fout, string sortname, double s[], int durationtime)
{
    int incr = 10000;
    int j = 1;
    double relcompares, relcopies;
    relcompares = (double)numcompares / maxnum;
    relcopies = (double)numcopies / maxnum;
    fout << endl << endl << "Sort Name: " << sortname << endl;
    fout << "Time taken by sorting function: " << durationtime << " microseconds" << endl;
    fout.setf(ios::fixed);
    fout.precision(4);
    for( int i = 0; i < maxnum; i += incr)
    {
        fout << setw(13) << s[i];
        j++;
        if(j > 4)
        {
            fout << endl;
            j = 1;
        }
    }
    fout << endl << setw(30) << "# of Compares = " << numcompares << setw(30) << "# of Copies = " << numcopies << endl << setw(30) << "Relative # of Compares = " << relcompares << setw(30) << "Relative # of Copies = " << relcopies << endl;
}

bool sortbyval(const pair<string, int> &a, const pair<string, int> &b)
{
    return(a.second < b.second);
}

int seqsearch(double dataset[],int target,int n){
  bool found=false;
  int pos=-1;
  for(int i=0;i<n && found!=true;i++)
     if(target==dataset[i]){pos=i;found=true;}

   return pos;
}

int binarySearch(double arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    randNumGenerator();
    ofstream fout("timeComplexity.txt");
    string sortname = "";
    string searchname = "";
    double data[maxnum + 1] = {0};
    fout << "n = " << maxnum << endl;
    int bubavgtime = 0;
    int selavgtime = 0;
    int insavgtime = 0;
    int shavgtime = 0;
    int qavgtime = 0;
    int impavgtime  = 0;
    int meravgtime = 0;
    int havgtime = 0;
    int savgtime = 0;
    int ssavgtime = 0;
    int seqavgtime = 0;
    int biavgtime = 0;
    for(int i = 0; i < 12; i++)
    {
        readem(data);
        numcopies = 0;
        numcompares = 0;
        int durationtime;
        int n = sizeof(data)/sizeof(data[0]);
        switch(i)
        {
            case 0:
            {
                sortname = "bubblesort";
                auto start = high_resolution_clock::now();
                bubblesort(data);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    bubblesort(data);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                bubavgtime = totaltime/10;
                fout << "Average Time: " << bubavgtime << endl;
                break;
            }
            case 1:
            {
                sortname = "selectsort";
                auto start = high_resolution_clock::now();
                selectsort(data);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    selectsort(data);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                selavgtime = totaltime/10;
                fout << "Average Time: " << selavgtime << endl;
                break;
            }
            case 2:
            {
                sortname = "insertsort";
                auto start = high_resolution_clock::now();
                insertsort(data);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    insertsort(data);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                insavgtime = totaltime/10;
                fout << "Average Time: " << insavgtime << endl;
                break;
            }
            case 3:
            {
                sortname = "shellsort";
                auto start = high_resolution_clock::now();
                shellsort(data, n);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    shellsort(data, n);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                shavgtime = totaltime/10;
                fout << "Average Time: " << shavgtime << endl;
                break;
            }
            case 4:
            {
                sortname = "quicksort";
                auto start = high_resolution_clock::now();
                quicksort(data, 0, maxnum - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    quicksort(data, 0, maxnum-1);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                qavgtime = totaltime/10;
                fout << "Average Time: " << qavgtime << endl;
                break;
            }
            case 5:
            {
                sortname = "improved bubblesort";
                auto start = high_resolution_clock::now();
                improvedBubblesort(data);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    improvedBubblesort(data);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                impavgtime = totaltime/10;
                fout << "Average Time: " << impavgtime << endl;
                break;
            }
            case 6:
            {
                sortname = "mergesort";
                auto start = high_resolution_clock::now();
                mergeSort(data, 0, maxnum);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    mergeSort(data, 0, maxnum);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                 }
                meravgtime = totaltime/10;
                fout << "Average Time: " << meravgtime << endl;
                break;
            }
            case 7:
            {
                sortname = "heapsort";
                auto start = high_resolution_clock::now();
                heapSort(data, n);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    heapSort(data, n);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                havgtime = totaltime/10;
                fout << "Average Time: " << havgtime << endl;
                break;
            }
            case 8:
            {
                sortname = "algorithm.h/sort";
                auto start = high_resolution_clock::now();
                sort(data, data+n);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    sort(data, data+n);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                savgtime = totaltime/10;
                fout << "Average Time: " << savgtime << endl;
                break;
            }
            case 9:
            {
                sortname = "algorithm.h/stable_sort";
                auto start = high_resolution_clock::now();
                stable_sort(data, data+n);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                printem(fout, sortname, data, durationtime);
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    stable_sort(data, data+n);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                }
                ssavgtime = totaltime/10;
                fout << "Average Time: " << ssavgtime << endl << endl;
                break;
            }
            case 10:
            {
                int pos = 0;
                searchname = "sequential search";
                auto start = high_resolution_clock::now();
                pos = seqsearch(data, 395.9183, n);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                fout << endl << endl << "Search Name: " << searchname << endl;
                fout << "Time taken by sorting function: " << durationtime << " microseconds" << endl;
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    pos = seqsearch(data, 395.9183, n);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                 }
                seqavgtime = totaltime/10;
                fout << "Average Time: " << seqavgtime << endl;
                break;
            }
            case 11:
            {
                int pos = 0;
                searchname = "binary search";
                auto start = high_resolution_clock::now();
                pos = binarySearch(data, 0, maxnum, 395.9183);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                durationtime = duration.count();
                fout << endl << endl << "Search Name: " << searchname << endl;
                fout << "Time taken by sorting function: " << durationtime << " microseconds" << endl;
                int totaltime = 0;
                for(int j = 0; j < 10; j++)
                {
                    auto start = high_resolution_clock::now();
                    pos = binarySearch(data, 0, maxnum, 395.9183);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    durationtime = duration.count();
                    totaltime += durationtime;
                 }
                biavgtime = totaltime/10;
                fout << "Average Time: " << biavgtime << endl;
                break;
            }
            default:
                break;
        }
    }
    map<string, int> time = {{"bubblesort", bubavgtime}, {"selectsort", selavgtime}, {"insertsort", insavgtime}, {"shellsort", shavgtime}, {"quicksort", qavgtime}, {"improved bubblesort", impavgtime}, {"mergesort", meravgtime}, {"heapsort", havgtime}, {"algorithm.h/sort", savgtime}, {"algorithm.h/stable_sort", ssavgtime}};
    vector<pair<string, int>> vec;
    map<string, int> :: iterator it;
    for(it=time.begin(); it!=time.end(); it++)
    {
        vec.push_back(make_pair(it->first, it->second));
    }
    sort(vec.begin(), vec.end(), sortbyval);
    fout << endl << "Sorts Organized By Time In Microseconds:" << endl;
    for(int k = 0; k <vec.size(); k++)
    {
        fout << vec[k].first << " " << vec[k].second << endl;
    }
    return 0;
}

