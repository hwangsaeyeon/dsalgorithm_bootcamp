 def solution(A,B):
    answer = 0

    A.sort() 
    B.sort(reverse=True)
    
    for i in range(len(A)): 
        answer += A[i] * B[i]
    
    return answer

#참고로 max(A)*min(B) 후 del A[A.index(max(A))], B[B.index(min(B))]는 시간 초과됨 
#sum([a * b for a, b in zip(sorted(A), sorted(B, reverse=True))])
