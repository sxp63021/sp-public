
class Solution:
    def isValid(self, s: str):
        # len(input)
       
        if (len(s) == 0):
            return True
            
        if (len(s) == 1):
            return False
    
        mydict = {"}":"{", "]":"[", ")":"("}
        
        #save on the open braces
        stack = []
        for i in s:
            
            if i in mydict.keys():
                #mydict[i] - get the value to match what you want to remove
                if (len(stack) == 0):
                    return False
                
                if (stack[-1] == mydict[i]):
                    stack.pop()
                else:
                    return False
            else:
                stack.append(i);
        
        if (len(stack) == 0):
            return True
        else:
            return False
        
