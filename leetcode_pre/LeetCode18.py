



class Solution:
    def fourSum(nums, target):
        """
        :param nums:  List[int]
        :param target: int
        :return: List[List[int]]
        """
        def findComb(nums, size, target, start, ansSize, ans, tempAns):
            """
            :param nums:
            :param size:  nums的大小
            :param target:  求和的目标数
            :param start:   从nums下标start开始
            :param ansSize:  要找ansSize个数
            :param ans:     存放找到的满足的答案
            :param tempAns:  存放目前已经找到的4个数中的某些
            :return:
            """

            if sum(nums[start:start+ansSize]) > target:
                return
            if sum(nums[-ansSize:]) < target:
                return

            if ansSize == 2:
                i  = start
                j =  size-1
                while(i < j):
                    twosum = nums[i] + nums[j]
                    if twosum < target:
                        i+=1
                    elif twosum > target:
                        j-=1
                    else:
                        ans.append(tempAns+[nums[i], nums[j]])
                        j -= 1
                        while(i < j and nums[j] == nums[j +1]):
                            j -= 1
                        i += 1
                        while(i < j and nums[i] == nums[i - 1]):
                            i += 1
            else:
                for i in range(start, size-ansSize+1):
                    print(tempAns)
                    if i > start and nums[i] == nums[i - 1]:
                        continue
                    findComb(nums, size, target - nums[i], i + 1, ansSize - 1, ans, tempAns + [nums[i]])


        ans = []
        size = len(nums)

        if size < 4:
            return []
        if size == 4:
            if sum(nums) == target:
                return [nums]
            else:
                return

        nums.sort()
        findComb(nums, size, target, 0, 4, ans, [])

        return ans

if __name__ == '__main__' :

    sl = Solution

    nums = [-1,0,1,2,-1,-4]
    nums = [-4, -1, -1, 0, 1, 2]
    target = -1
    ans = sl.fourSum(nums,target)
    print(ans)








