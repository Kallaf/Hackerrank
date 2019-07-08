#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+3);
    for(int i=1;i<=n;i++)
        cin >> arr[i];

    //Try swap
    int count_unsorted = 0,i1=1,i2=1;
    bool first=1;
    for(int i=2;i<=n;i++)
    {
        if(first)
        {
            if(arr[i] < arr[i-1])
            {
                i1 = i-1;
                i2 = i;
                first = 0;
                count_unsorted++;
                if(count_unsorted > 2)break;
            }
        }else{
            if(arr[i] < arr[i2])
            {
                i2 = i;
                first = 1;
                count_unsorted++;
            }
        }
    }
    if(count_unsorted <= 2)
    {
        bool sorted = 1;
        swap(arr[i1],arr[i2]);
        if(!((i1 > 1 && arr[i1] <arr[i1-1]) || (i2 < n && arr[i2] >arr[i2+1])))
        {
            printf("yes\nswap %d %d\n",i1,i2);
            return 0;
        }
        swap(arr[i1],arr[i2]);
    }

    //Try reverse
    pair<int,int> range;
    bool asc = 1;
    int desc = 0,max_asc = -1,max_desc;
    for(int i=2;i<=n;i++)
    {
        if(asc)
        {
            if(arr[i] < arr[i-1])
            {
                asc = 0;
                desc++;
                if(desc > 1)
                {
                    cout << "no\n";
                    return 0;
                }
                range = make_pair(i-1,i);
                max_desc = arr[i-1];
                if(i != 2)max_asc = arr[i-2];
                if(max_asc > arr[i])
                {
                    cout << "no\n";
                    return 0;
                }
            }
        }else{
            if(arr[i] <= arr[i-1])
            {
                if(max_asc > arr[i])
                {
                    cout << "no\n";
                    return 0;
                }
                range.second = i;
            }else{
                asc = 1;
                if(arr[i] < max_desc)
                {
                    cout << "no\n";
                    return 0;
                }
            }
        }
        
    }
    printf("yes\nreverse %d %d\n",range.first,range.second);
    return 0;
}
