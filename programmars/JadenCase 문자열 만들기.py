def solution(s):
    answer = ''
    split = s.split(" ")
    for i in range(len(split)): 
        if len(split[i]) > 0: 
            split[i] = split[i].lower() #공백문자 

            if split[i][0].isdigit() == True:
                pass
            else: 
                split[i] = split[i].capitalize()

    answer = ' '.join(split)
    return answer
