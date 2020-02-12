class Solution(object):
    def getInterNum(self,n):#这里相当于都是定值了，因为传进来的都是
    #0,10,100,1000这样的数，对应分别是0,1,20,300,4000，比如n=1000时表示0-999所包含的1的
    #个数 算法也是从低位向高位算，输入10（其实在算小于等于9的）的就是返回1，100（其实是99）就是1+9*1+10,1是91到99之间的1，也就是上一步dp的结果，9*1是上一步的1，我在前面添加了9个不同的数，所以是9*1,10是10-19的1,11中的一个1在9*1的时候算过了，所以并没有少算。
        s = math.pow(10,n-1)
        return n*s
    def countDigitOne(self, n):
        if n <= 0:
            return 0
        Sum = 0;
        cir = 0
        N = n
        while n:
            t = n%10
            n = n/10
            if t==0:
                cir+=1
            elif t != 1:
                Sum = Sum+t*self.getInterNum(cir)+math.pow(10,cir)
                cir+=1
            else:
                Sum = Sum+N%math.pow(10,cir)+1+self.getInterNum(cir)
                cir+=1
        return int(Sum)