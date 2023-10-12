# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        n=mountain_arr.length()
        l=1
        r=n-2
        peak=-1
        while l<=r:
            m=(l+r)//2
            a=mountain_arr.get(m-1)
            b=mountain_arr.get(m)
            c=mountain_arr.get(m+1)
            if b>a and b>c: 
                peak=m
                break
            elif b>a and b<c:
                l=m+1
            else:
                r=m-1
        if(mountain_arr.get(m)==target):
            return m
        l,r=0,m-1
        while l<=r:
            k=(l+r)//2
            if(mountain_arr.get(k)==target):
                return k
            elif mountain_arr.get(k)>target:
                r=k-1
            else:
                l=k+1
        l,r=m+1,n-1
        while l<=r:
            k=(l+r)//2
            if(mountain_arr.get(k)==target):
                return k
            elif mountain_arr.get(k)<target:
                r=k-1
            else:
                l=k+1
        
        return -1