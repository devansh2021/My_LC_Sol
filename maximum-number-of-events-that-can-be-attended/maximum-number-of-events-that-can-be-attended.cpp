class Solution
{
  vector<vector<int>> dp;

public:
  int maxEvents(vector<vector<int>> &A)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.begin(), A.end());
    int i = 0, res = 0, n = A.size();
    for (int d = 1; d <= 100000; ++d)
    {
      //if the event at heap top already ended, then discard it.
      while (pq.size() && pq.top() < d)
        pq.pop();
      //all events starting from today are newly available.add them to the heap.
      while (i < n && A[i][0] == d)
        pq.push(A[i++][1]);
      //attend the event that will end the earliest
      if (pq.size())
      {
        pq.pop();
        ++res;
      }
    }
    return res;
  }
};