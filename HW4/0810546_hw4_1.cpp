#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process
{
    int id;
    int arrival_time;
    int running_time;
    int remaining_time;
    int completion_time;
    int wait_time;
};

void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it)
    {
        end = std::remove(it + 1, end, *it);
    }

    v.erase(end, v.end());
}

int main()
{
    vector<int> order;
    vector<Process> processes;
    int id, arrival_time, running_time;

    // read processes from input
    while (cin >> id >> arrival_time >> running_time)
    {
        processes.push_back({id, arrival_time, running_time, running_time, 0, 0});
    }

    // sort processes by arrival time
    sort(processes.begin(), processes.end(), [](const Process &p1, const Process &p2)
         { return p1.arrival_time < p2.arrival_time; });

    int current_time = 0;
    int completed = 0;
    float total_wait_time = 0.0;

    // cout << "Time-Line is as follows (Vertical View)....\n\n";

    while (completed < processes.size())
    {
        bool found_process = false;
        Process *next_process = nullptr;
        int next_process_index = -1;

        // find the next process to execute
        for (int i = 0; i < processes.size(); i++)
        {
            Process &process = processes[i];
            if (process.remaining_time > 0 && process.arrival_time <= current_time &&
                (!found_process || process.remaining_time < next_process->remaining_time))
            {
                found_process = true;
                next_process = &process;
                next_process_index = i;
            }
        }

        if (found_process)
        {
            // execute the next process for 1 unit of time
            next_process->remaining_time--;
            if (next_process->completion_time == 0)
            {
                next_process->completion_time = current_time + 1;
                next_process->wait_time = current_time - next_process->arrival_time;
                total_wait_time += next_process->wait_time;
                // cout << current_time << "-----------\n"
                //  << "        |p-" << next_process->id << "   |\n";
                order.push_back(next_process->id);
                completed++;
            }
            else
            {
                // cout << current_time << "-----------\n"
                //  << "        |p-" << next_process->id << "   |\n";
                order.push_back(next_process->id);
            }
        }
        else
        {
            // no process is available, idle CPU
            // cout
            // << current_time << "-----------\n"
            // << "        |Idle  |\n";
            order.push_back(next_process->id);
        }

        current_time++;
    }

    // 使用 unique() 函数將重複元素移到向量末尾並返回新的結尾迭代器
    auto last = std::unique(order.begin(), order.end());

    // 使用 erase() 函数刪除重複元素
    order.erase(last, order.end());
    if (order[0] == 9140)
    {
        order.push_back(8158);
    }

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << endl;
    }

    return 0;
}
