#include "interval.h"

bool earlier_than_or_equal(time_of_day t1, time_of_day t2) {
    if (t1.h < t2.h || (t1.h == t2.h && t1.m <= t2.m)) {
        return true;
    }
    return false;
}

bool check_equal(time_of_day t1, time_of_day t2) {
    if ((t1.h == t2.h) && (t1.m == t2.m)) {
        return true;
    }
    return false;
}

bool check_if_time_is_in_interval(interval inter, time_of_day time) {
    if (earlier_than_or_equal(inter.start, time) && earlier_than_or_equal(time, inter.end)) {
        return true;
    }
    return false;
}

bool check_if_the_intervals_contain_each_other(interval a, interval b) {
    if (check_if_time_is_in_interval(b, a.start) || check_if_time_is_in_interval(b, a.end)) {
        return true;
    }
    if (check_if_time_is_in_interval(a, b.start) || check_if_time_is_in_interval(a, b.end)) {
        return true;
    }
    return false;
}

interval reduce_1_minute(interval inter) { // isto falha quando o inicio e o fim do intervalo forem iguais, mas os stores n falaram sobre isso no enunciado por isso n sei o q fazer nesse caso, pq e suposto o inicio tar incluido mas o fim ser estrictamente inferior
    inter.end.m--;
    if (inter.end.m < 0) {
        inter.end.m = 59;
        inter.end.h--;
    }
    return inter;
}

time_of_day reduce_1_minute_time(time_of_day time) {
    time.m--;
    if (time.m < 0) {
        time.m = 59;
        time.h--;
    }
    return time;
}


// esta era para se fosse para fazer a interseção, mas é suposto fazer a união
// interval joins_intervals(interval a, interval b) {
//     // we can assume that the intervals can be joined
//     interval res;
//     // in the case that the interval a is contained inside the interval b
//     if (check_if_time_is_in_interval(b, a.start) && check_if_time_is_in_interval(b, a.end)) {
//         res.start = a.start;
//         res.end = a.end;
//         return res;
//     }
//     // in the case that the interval b is contained inside the interval a
//     if (check_if_time_is_in_interval(a, b.start) && check_if_time_is_in_interval(a, b.end)) {
//         res.start = b.start;
//         res.end = b.end;
//         return res;
//     }
//     // in the case both intervals are equal (already covered in the previous 2)
//     // in the case a end and b start is the same (in the case a start < a end == b start < b end)
//     if (check_equal(reduce_1_minute_time(a.end), b.start)) {
//         res.start = a.start;
//         res.end = b.end;
//         return res;
//     }
//     // in the case b end and a start is the same (in the case b start < b end == a start < a end)
//     if (check_equal(reduce_1_minute_time(b.end), a.start)) {
//         res.start = b.start;
//         res.end = a.end;
//         return res;
//     }
//     // in the case a start < b start < a end < b end
//     if (check_if_time_is_in_interval(a, b.start) && check_if_time_is_in_interval(b, reduce_1_minute_time(a.end))) {
//         res.start = b.start;
//         res.end = a.end;
//         return res;
//     }
//     // in the case b start < a start < b end < a end
//     if (check_if_time_is_in_interval(b, a.start) && check_if_time_is_in_interval(a, reduce_1_minute_time(b.end))) { // aqui podia ser um else
//         res.start = a.start;
//         res.end = b.end;
//         return res;
//     }
//     return res; // nunca é suposto chegar aqui
// }

// esta aqui é a união
interval joins_intervals(interval a, interval b) {
    // we can assume that the intervals can be joined
    interval res;
    // in the case that the interval a is contained inside the interval b
    if (check_if_time_is_in_interval(b, a.start) && check_if_time_is_in_interval(b, a.end)) {
        res.start = a.start;
        res.end = a.end;
        return res;
    }
    // in the case that the interval b is contained inside the interval a
    if (check_if_time_is_in_interval(a, b.start) && check_if_time_is_in_interval(a, b.end)) {
        res.start = b.start;
        res.end = b.end;
        return res;
    }
    // in the case both intervals are equal (already covered in the previous 2)
    // in the case a end and b start is the same (in the case a start < a end == b start < b end)
    if (check_equal(reduce_1_minute_time(a.end), b.start)) {
        res.start = a.start;
        res.end = b.end;
        return res;
    }
    // in the case b end and a start is the same (in the case b start < b end == a start < a end)
    if (check_equal(reduce_1_minute_time(b.end), a.start)) {
        res.start = b.start;
        res.end = a.end;
        return res;
    }
    // in the case a start < b start < a end < b end
    if (check_if_time_is_in_interval(a, b.start) && check_if_time_is_in_interval(b, reduce_1_minute_time(a.end))) {
        res.start = a.start;
        res.end = b.end;
        return res;
    }
    // in the case b start < a start < b end < a end
    if (check_if_time_is_in_interval(b, a.start) && check_if_time_is_in_interval(a, reduce_1_minute_time(b.end))) { // aqui podia ser um else
        res.start = b.start;
        res.end = a.end;
        return res;
    }
    return res; // nunca é suposto chegar aqui
}

int get_duration_from_interval(interval inter) {
    int res = 0;
    int hour = 0;
    res = inter.end.m - inter.start.m;
    if (res < 0) {
        hour--;
    }
    hour = inter.end.h - inter.start.h;
    return res + hour * 60;
}


int search_intervals(time_of_day t, const interval a[], int n, interval& u) {
    bool inter_contain_t[214748]; // o ideal era pôr "bool inter_contain_t[n];", mas o compilador dá warning e tá para todos os warnings serem interpretados como erros então simplesmente pus um coiso tão grande que nenhum dos testes vai ultrapassar
    // goes through all intervals checking if t is in them
    bool flag = false;
    for (int i = 0; i < n; i++) {
        interval current_inter = reduce_1_minute(a[i]); 
        if (check_if_time_is_in_interval(current_inter, t)) {
            inter_contain_t[i] = true;
            flag = true;
            continue;
        }
        inter_contain_t[i] = false;
    }
    // gets the union between all the intervals that contain t
    for (int i = 0; i < n; i++) {
        if (inter_contain_t[i] == true) {
            u = a[i];
            for (int j = i; j < n; j++) { // vai tar a juntar com ele próprio uma vez mas pronto
                if (inter_contain_t[j] == true) {
                    // if (check_if_the_intervals_contain_each_other(u, a[j])) { // tecnicamente é desnecessário fazer isto pq pronto já sabemos q vai tar, só que eu já tinha escrito a função e só depois é que reparei que n era preciso ¯\_(ツ)_/¯
                        u = joins_intervals(u, a[j]);
                    // }
                }
            }
            break;
        }
    }
    if (flag == false) {
        u.start = t;
        u.end = t;
    }
    // gets the duration of the union of intervals in minutes
    return get_duration_from_interval(u);
}


// int main() {
//     const int n = 5;
//     const time_of_day t = { 15, 15 };
//     const interval a[n] { { { 12, 30 }, { 14, 30 } },
//                     { { 14, 30 }, { 15, 30 } },
//                     { { 15, 10 }, { 16, 10 } },
//                     { {  9, 30 }, { 15, 15 } },
//                     { {  9, 45 }, { 15, 16 } } };
//     interval u;
//     int d = search_intervals(t, a, n, u);
//     cout << d << ' ' << u << '\n';
// }