"""
Daniel Lee, Joel Singh
January 27, 2025
DLeeJSingh_cs173_project1.py
This program simulates a situation where there are two people, and each person enters the kitchen starting at midnight, stays for a certain period, and then leaves for a specific amount of time, repeating this cycle throughout the day. At a specific time, starting at midnight, Soprano the cat attempts to hop up on the counter. The program determines whether Soprano succeeds if no one is in the kitchen or gets caught if someone is.
"""
    
def getParam():
    """A function that receives five inputs to simulate the situation and returns five integers.
    
    Parameters:
        None

    Return value:
        p1_in: length of time (in minutes) person 1 stays in the kitchen
        p1_out: length of time (in minutes) person 1 stays out of the kitchen
        p2_in: length of time (in minutes) person 2 stays in the kitchen
        p2_out: length of time (in minutes) person 2 stays out of the kitchen
        t_hop: the time in minutes after midnight when Soprano attempts to hop
    """
    p1_in = int(input())
    p1_out = int(input())
    
    p2_in = int(input())
    p2_out = int(input())
    
    t_hop = int(input())
    
    return p1_in, p1_out, p2_in, p2_out, t_hop
    
    
def checkCaught(p1_in, p1_out, p2_in, p2_out, t_hop):
    """A function that checks if Soprano the cat gets caught or not

    Parameters:
        p1_in: length of time (in minutes) person 1 stays in the kitchen
        p1_out: length of time (in minutes) person 1 stays out of the kitchen
        p2_in: length of time (in minutes) person 2 stays in the kitchen
        p2_out: length of time (in minutes) person 2 stays out of the kitchen
        t_hop: the time in minutes after midnight when Soprano attempts to hop
        
    Return value:
        None
    """
    HOUR_AS_MINUTES = 24*60
    t_hop = t_hop % HOUR_AS_MINUTES

    if (p1_in == 0 and p1_out == 0) or (p2_in == 0 and p2_out == 0):
        raise TypeError("in and out are both 0, what to do? Ask teacher")
    
    p1_cycle = p1_in + p1_out
    p2_cycle = p2_in + p2_out
    
    p1_modulo = t_hop % p1_cycle
    p2_modulo = t_hop % p2_cycle
    
    caught_by_p1 = p1_modulo < p1_in
    caught_by_p2 = p2_modulo < p2_in
    
    if caught_by_p1 or caught_by_p2:
        print("CAUGHT")
    else:
        print("SUCCESS")
        
        
if __name__ == "__main__":
    p1_in, p1_out, p2_in, p2_out, t_hop = getParam()
    checkCaught(p1_in, p1_out, p2_in, p2_out, t_hop)
