/*
 * Copyright (c) 2022, Undefine <undefine@undefine.pl>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/DOSPackedTime.h>

namespace AK {

UnixDateTime time_from_packed_dos(DOSPackedDate date, DOSPackedTime time)
{
    if (date.value == 0)
        return UnixDateTime::from_unix_time_parts(first_dos_year, 1, 1, 0, 0, 0, 0);

    return UnixDateTime::from_unix_time_parts(first_dos_year + date.fields.year, date.fields.month, date.fields.day, time.fields.hour, time.fields.minute, time.fields.second * 2, 0);
}

DOSPackedDate to_packed_dos_date(unsigned year, unsigned month, unsigned day)
{
    DOSPackedDate date;
    date.fields.year = year - first_dos_year;
    date.fields.month = month;
    date.fields.day = day;

    return date;
}

DOSPackedTime to_packed_dos_time(unsigned hour, unsigned minute, unsigned second)
{
    DOSPackedTime time;
    time.fields.hour = hour;
    time.fields.minute = minute;
    time.fields.second = second / 2;

    return time;
}

}
