def _2271(iterable):

    if len(iterable) == 1 or len(iterable) == 0:
        return -1

    if len(iterable) == 2:
        if iterable[0] < 0 <= iterable[1]:
            return -1
        elif iterable[1] < 0 <= iterable[0]:
            return -1

    negativ_x, negativ_y = 0 , 0
    x, y = -1, -1
    produs_negativ, produs_positiv = 0 , 0

    for i in iterable:
        if i<0 :
            if i<=negativ_x and negativ_x>=negativ_y:
                negativ_x=i
            elif i<=negativ_y and negativ_y>=negativ_x:
                negativ_y=i
        else :
            if i>=x and x<=y :

                x=i
            elif i>=y and y<=x :
                y=i

    if negativ_x != 0 and negativ_y != 0 :
        produs_negativ = negativ_x*negativ_y
    if x != -1 and y != -1:
        produs_positiv = x*y

    return max(produs_negativ, produs_positiv)

def test_2271() :
    assert _2271([]) == -1
    assert _2271([1]) == -1
    assert _2271([-1, 0]) == -1
    assert _2271([0, -7]) == -1
    assert _2271([-1, 4, -5, 6, -2, -1, -8, 3, 9]) == 54
    print('All the tests passed!')

test_2271()
