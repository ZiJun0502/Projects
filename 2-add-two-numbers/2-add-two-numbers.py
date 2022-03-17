# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class linklist:
    def __init__(self,head):
        self.head=head
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result=[]
        st1=st2=''
        while True:
            if l1==None:
                break
            st1=str(l1.val)+st1
            l1=l1.next
        while True:
            if l2==None:
                break
            st2=str(l2.val)+st2
            l2=l2.next
        ans=str(eval(st1+'+'+st2))[::-1]
        head=ListNode(int(ans[0]),None)
        c=head
        for i in ans[1::]:
            c.next=ListNode(int(i),None)
            c=c.next
        return head