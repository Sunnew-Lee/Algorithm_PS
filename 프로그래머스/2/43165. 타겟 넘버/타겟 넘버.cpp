#include <string>
#include <vector>

using namespace std;

int SUM{0},answer{0};

void func(vector<int>& nums, int depth, int target)
{
    if(depth == nums.size())
    {
        if(SUM == target)
        {
            ++answer;
        }           
        return;
    }
    
    SUM+=nums[depth];
    func(nums, depth+1, target);
    SUM-=nums[depth];
    
    SUM-=nums[depth];
    func(nums, depth+1, target);    
    SUM+=nums[depth];
}

int solution(vector<int> numbers, int target) {

    func(numbers, 0, target);    
    
    return answer;
}