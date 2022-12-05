#include <bits/stdc++.h>
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (!pq.empty())
            return pq[0];
        else
            return 0;
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {

            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
                break;
            childIndex = parentIndex;
        }
    }
    int removeMin()
    {
        if (isEmpty())
            return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int pi = 0;
        int lci = (2 * pi) + 1;
        int rci = (2 * pi) + 2;
        while (lci < pq.size())
        {
            lci = (2 * pi) + 1;
            rci = (2 * pi) + 2;
            int mini = pi;
            if (pq[mini] > pq[lci])
                mini = lci;
            if (pq[mini] > pq[rci] && rci < pq.size())
                mini = rci;
            if (mini == pi)
                break;
            swap(pq[pi], pq[mini]);
            pi++;
        }
        return ans;
    }
};