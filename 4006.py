def _4006(n, a, b):
    
    if a>=b :
        return -1
    if n<=a :
        return -1

    copy_n = n
    nr_a, nr_b = 0, 0
    stop = False
    while True :
        if n-a >= b and not stop :
            n-=a
            nr_a+=1
        else :
            if n == copy_n :
                return -1
            else :
                stop = True
                if n % b == 0 :
                    nr_b = n // b
                    break
                else :
                    n = n+a
                    nr_a = nr_a -1

    if nr_a > nr_b :
        return nr_a, nr_b
    else :
        return -1

def test_4006():

    assert _4006(4, 1, 2) == (2, 1)
    assert _4006(4, 2, 2) == -1
    assert _4006(40, 3, 5) == (10, 2)
    assert _4006(40, 5, 3) == -1
    print('All tests passed!')

test_4006()
