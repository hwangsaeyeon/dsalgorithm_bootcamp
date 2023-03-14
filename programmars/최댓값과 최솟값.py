def solution(s):
    answer = ''
    s = s.split(' ')
    s = list(map(lambda x: int(x), s))
    
    maxnum = max(s)
    minnum = min(s)
    answer = "%s %s"%(minnum, maxnum)
        
    return answer
