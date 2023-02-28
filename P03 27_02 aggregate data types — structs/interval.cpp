#include "interval.h"

bool equal(time_of_day a, time_of_day b) {
    return (a.h == b.h) && (a.m == b.m);
}

bool earlier_than(time_of_day a, time_of_day b) {
    //caso em q as horas são iguais
    if (a.h == b.h) {
        if (a.m >= b.m) {
            return false;
        }
        return true;
    }
    if (a.h < b.h) {
        return true;
    }
    return false;
}

interval intersection(interval a, interval b) {
    time_of_day zero;
    zero.h = 0;
    zero.m = 0; 
    interval i;
    i.start = zero;
    i.end = zero;
    if (equal(a.start, b.start) && equal(a.end, b.end)) {
        i = a;
        return i;
    }
    if (earlier_than(b.start, a.end)) {
        if (earlier_than(b.start, a.start) && earlier_than(a.start, b.end)) {
            if (earlier_than(a.end, b.end)) {
                i = a;
                return i;
            }
            i.start = a.start;
            i.end = b.end;
            return i;
        }
        if (earlier_than(a.start, b.end) && earlier_than(a.end, b.end)) {
            i.start = b.start;
            i.end = a.end;
            return i;
        }
    }
    if (earlier_than(a.start, b.end)) {
        if (earlier_than(a.start, b.start) && earlier_than(b.start, a.end)) {
            if (earlier_than(b.end, a.end)) {
                i = b;
                return i;
            }
            i.start = b.start;
            i.end = a.end;
            return i;
        }
        if (earlier_than(b.start, a.end) && earlier_than(b.end, a.end)) {
            i.start = a.start;
            i.end = b.end;
            return i;
        }
    }
    return i;
}





//TESTES

bool check(interval a, interval b) {
    return (equal(a.start, b.start) && equal(a.end, b.end));
}

int main() {
    interval result;
    time_of_day start;
    time_of_day end;

    start.h = 22;
    start.m = 45;
    end.h = 23;
    end.m = 59;
    result.start = start;
    result.end = end;
    cout << 1 << ' ';
    cout << check(intersection( { { 22,  45 }, { 23, 59 } },
                            { { 22, 45 }, { 23, 59 } } ), result);
    cout << " teste para quando os dois intervalos são exatamente iguais { { 22,  45 }, { 23, 59 } }, { { 22, 45 }, { 23, 59 } } -> ";
    cout << intersection( { { 22,  45 }, { 23, 59 } },
                            { { 22, 45 }, { 23, 59 } } ) << '\n';

    start.h = 0;
    start.m = 0;
    end.h = 0;
    end.m = 0;
    result.start = start;
    result.end = end;
    cout << 2 << ' ';
    cout << check(intersection( { { 12, 30 }, { 14, 30 } },
                            { { 17, 30 }, { 18, 30 } }  ), result);
    cout << " teste quando os intervalos não coincidem { { 12, 30 }, { 14, 30 } }, { { 17, 30 }, { 18, 30 } } -> ";
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                            { { 17, 30 }, { 18, 30 } } ) << '\n';

    start.h = 0;
    start.m = 0;
    end.h = 0;
    end.m = 0;
    result.start = start;
    result.end = end;
    cout << 3 << ' ';
    cout << check(intersection( { { 12, 30 }, { 14, 30 } },
                            { { 14, 30 }, { 18, 30 } }  ), result);
    cout << " teste quando os intervalos coincidem, mas o intervalo entre os dois é vazio { { 12, 30 }, { 14, 30 } }, { { 14, 30 }, { 18, 30 } } -> ";
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                            { { 14, 30 }, { 18, 30 } } ) << '\n';

    start.h = 14;
    start.m = 30;
    end.h = 14;
    end.m = 31;
    result.start = start;
    result.end = end;
    cout << 4 << ' ';
    cout << check(intersection(  { { 12, 30 }, { 14, 31 } },
                            { { 14, 30 }, { 18, 30 } }), result);
    cout << " teste quando os intervalos coincidem entre os minutos e a < b { { 12, 30 }, { 14, 31 } }, { { 14, 30 }, { 18, 30 } } -> ";
    cout << intersection( { { 12, 30 }, { 14, 31 } },
                            { { 14, 30 }, { 18, 30 } } ) << '\n';

    start.h = 14;
    start.m = 30;
    end.h = 14;
    end.m = 31;
    result.start = start;
    result.end = end;
    cout << 5 << ' ';
    cout << check(intersection( { { 14, 30 }, { 18, 30 } },
                            { { 12, 30 }, { 14, 31 } }  ), result);
    cout << " teste quando os intervalos coincidem entre os minutos e b < a { { 14, 30 }, { 18, 30 } }, { { 12, 30 }, { 14, 31 } } -> ";
    cout << intersection( { { 14, 30 }, { 18, 30 } },
                            { { 12, 30 }, { 14, 31 } } ) << '\n';

    start.h = 14;
    start.m = 30;
    end.h = 14;
    end.m = 31;
    result.start = start;
    result.end = end;
    cout << 6 << ' ';
    cout << check(intersection({ { 11, 30 }, { 15, 59 } },
                            { { 14, 30 }, { 14, 31 } }  ), result);
    cout << " teste quando o intervalo b está completamente incluido dentro do intervalo a { { 11, 30 }, { 15, 59 } }, { { 14, 30 }, { 14, 31 } } -> ";
    cout << intersection( { { 11, 30 }, { 15, 59 } },
                            { { 14, 30 }, { 14, 31 } } ) << '\n';

    start.h = 14;
    start.m = 30;
    end.h = 14;
    end.m = 31;
    result.start = start;
    result.end = end;
    cout << 7 << ' ';
    cout << check(intersection({ { 14, 30 }, { 14, 31 } },
                            { { 11, 30 }, { 15, 59 } }  ), result);
    cout << " teste quando o intervalo a está completamente incluido dentro do intervalo b { { 14, 30 }, { 14, 31 } }, { { 11, 30 }, { 15, 59 } } -> ";
    cout << intersection( { { 14, 30 }, { 14, 31 } },
                            { { 11, 30 }, { 15, 59 } } ) << '\n';

    start.h = 11;
    start.m = 30;
    end.h = 14;
    end.m = 30;
    result.start = start;
    result.end = end;
    cout << 8 << ' ';
    cout << check(intersection({ { 10, 30 }, { 14, 30 } },
                            { { 11, 30 }, { 15, 30 } }  ), result);
    cout << " teste quando o intervalo a e b cruzam-se, com o a mais pequeno do que o b { { 10, 30 }, { 14, 30 } }, { { 11, 30 }, { 15, 30 } } -> ";
    cout << intersection( { { 10, 30 }, { 14, 30 } },
                            { { 11, 30 }, { 15, 30 } }  ) << '\n';

    start.h = 11;
    start.m = 30;
    end.h = 14;
    end.m = 30;
    result.start = start;
    result.end = end;
    cout << 9 << ' ';
    cout << check(intersection({ { 11, 30 }, { 15, 30 } },
                            { { 10, 30 }, { 14, 30 } }), result);
    cout << " teste quando o intervalo a e b cruzam-se, com o b mais pequeno do que o a { { 11, 30 }, { 15, 30 } }, { { 10, 30 }, { 14, 30 } } -> ";
    cout << intersection( { { 11, 30 }, { 15, 30 } },
                            { { 10, 30 }, { 14, 30 } } ) << '\n';
    return 0;
}
