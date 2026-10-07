#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> customers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> customers[i].first >> customers[i].second;
    }
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
    {
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](int a, int b)
         {
    if(customers[a].first == customers[b].first){
        return customers[a].second<customers[b].second;
    }
    return customers[a].first<customers[b].first; });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> ans(n);
    int room_count = 0;
    for (int i = 0; i < n; i++)
    {
        int id = idx[i];
        int arrival = customers[id].first;
        int departure = customers[id].second;

        if (!pq.empty() && pq.top().first < arrival)
        {
            int free_room = pq.top().second;
            ans[id] = free_room;
            pq.pop();
            pq.push({departure, free_room});
        }
        else
        {
            room_count++;
            ans[id] = room_count;
            pq.push({departure, room_count});
        }
    }
    cout << room_count << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}