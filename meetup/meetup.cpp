#include "meetup.h"

namespace meetup {


scheduler::scheduler(boost::gregorian::greg_month month, int year) {
    this->month = month;
    this->year = year;
}

boost::gregorian::date scheduler::day_iterator(boost::gregorian::date start, boost::gregorian::greg_weekday day) {
    while (start.day_of_week() != day) {
        start += boost::gregorian::date_duration(1);
    }
    return start;
}

boost::gregorian::date scheduler::day_iterator_negative(boost::gregorian::date start,
    boost::gregorian::greg_weekday day) {
    while (start.day_of_week() != day) {
        start -= boost::gregorian::date_duration(1);
    }
    return start;
}

boost::gregorian::date scheduler::monteenth() const {
    return day_iterator(boost::gregorian::date(year, month, 13), boost::gregorian::Monday);
}

boost::gregorian::date scheduler::tuesteenth() const {
    return day_iterator(boost::gregorian::date(year, month, 13), boost::gregorian::Tuesday);

}

boost::gregorian::date scheduler::wednesteenth() const {
    return day_iterator(boost::gregorian::date(year, month, 13), boost::gregorian::Wednesday);

}

boost::gregorian::date scheduler::thursteenth() const {
    return day_iterator(boost::gregorian::date(year, month, 13), boost::gregorian::Thursday);

}

boost::gregorian::date scheduler::friteenth() const {
    return day_iterator(boost::gregorian::date(year, month, 13), boost::gregorian::Friday);

}

boost::gregorian::date scheduler::saturteenth() const {
    return day_iterator(boost::gregorian::date(year, month, 13), boost::gregorian::Saturday);

}

boost::gregorian::date scheduler::sunteenth() const {
    return day_iterator(boost::gregorian::date(year, month, 13), boost::gregorian::Sunday);

}

boost::gregorian::date scheduler::first_monday() const {
    return day_iterator(boost::gregorian::date(year, month, 1), boost::gregorian::Monday);
}

boost::gregorian::date scheduler::first_tuesday() const {
    return day_iterator(boost::gregorian::date(year, month, 1), boost::gregorian::Tuesday);

}

boost::gregorian::date scheduler::first_wednesday() const {
    return day_iterator(boost::gregorian::date(year, month, 1), boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::first_thursday() const {
    return day_iterator(boost::gregorian::date(year, month, 1), boost::gregorian::Thursday);
}

boost::gregorian::date scheduler::first_friday() const {
    return day_iterator(boost::gregorian::date(year, month, 1), boost::gregorian::Friday);
}

boost::gregorian::date scheduler::first_saturday() const {
    return day_iterator(boost::gregorian::date(year, month, 1), boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::first_sunday() const {
    return day_iterator(boost::gregorian::date(year, month, 1), boost::gregorian::Sunday);
}

boost::gregorian::date scheduler::second_monday() const {
    return day_iterator(boost::gregorian::date(year, month, 8), boost::gregorian::Monday);
}

boost::gregorian::date scheduler::second_tuesday() const {
    return day_iterator(boost::gregorian::date(year, month, 8), boost::gregorian::Tuesday);
}

boost::gregorian::date scheduler::second_wednesday() const {
    return day_iterator(boost::gregorian::date(year, month, 8), boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::second_thursday() const {
    return day_iterator(boost::gregorian::date(year, month, 8), boost::gregorian::Thursday);
}

boost::gregorian::date scheduler::second_friday() const {
    return day_iterator(boost::gregorian::date(year, month, 8), boost::gregorian::Friday);
}

boost::gregorian::date scheduler::second_saturday() const {
    return day_iterator(boost::gregorian::date(year, month, 8), boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::second_sunday() const {
    return day_iterator(boost::gregorian::date(year, month, 8), boost::gregorian::Sunday);
}

boost::gregorian::date scheduler::third_monday() const {
    return day_iterator(boost::gregorian::date(year, month, 15), boost::gregorian::Monday);
}

boost::gregorian::date scheduler::third_tuesday() const {
    return day_iterator(boost::gregorian::date(year, month, 15), boost::gregorian::Tuesday);
}

boost::gregorian::date scheduler::third_wednesday() const {
    return day_iterator(boost::gregorian::date(year, month, 15), boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::third_thursday() const {
    return day_iterator(boost::gregorian::date(year, month, 15), boost::gregorian::Thursday);

}

boost::gregorian::date scheduler::third_friday() const {
    return day_iterator(boost::gregorian::date(year, month, 15), boost::gregorian::Friday);
}

boost::gregorian::date scheduler::third_saturday() const {
    return day_iterator(boost::gregorian::date(year, month, 15), boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::third_sunday() const {
    return day_iterator(boost::gregorian::date(year, month, 15), boost::gregorian::Sunday);
}

boost::gregorian::date scheduler::fourth_monday() const {
    return day_iterator(boost::gregorian::date(year, month, 22), boost::gregorian::Monday);
}

boost::gregorian::date scheduler::fourth_tuesday() const {
    return day_iterator(boost::gregorian::date(year, month, 22), boost::gregorian::Tuesday);
}

boost::gregorian::date scheduler::fourth_wednesday() const {
    return day_iterator(boost::gregorian::date(year, month, 22), boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::fourth_thursday() const {
    return day_iterator(boost::gregorian::date(year, month, 22), boost::gregorian::Thursday);
}

boost::gregorian::date scheduler::fourth_friday() const {
    return day_iterator(boost::gregorian::date(year, month, 22), boost::gregorian::Friday);
}

boost::gregorian::date scheduler::fourth_saturday() const {
    return day_iterator(boost::gregorian::date(year, month, 22), boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::fourth_sunday() const {
    return day_iterator(boost::gregorian::date(year, month, 22), boost::gregorian::Sunday);
}

boost::gregorian::date scheduler::last_monday() const {
    return day_iterator_negative(boost::gregorian::date(year, month, 1).end_of_month(), boost::gregorian::Monday);
}

boost::gregorian::date scheduler::last_tuesday() const {
    return day_iterator_negative(boost::gregorian::date(year, month, 1).end_of_month(), boost::gregorian::Tuesday);
}

boost::gregorian::date scheduler::last_wednesday() const {
    return day_iterator_negative(boost::gregorian::date(year, month, 1).end_of_month(), boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::last_thursday() const {
    return day_iterator_negative(boost::gregorian::date(year, month, 1).end_of_month(), boost::gregorian::Thursday);
}

boost::gregorian::date scheduler::last_friday() const {
    return day_iterator_negative(boost::gregorian::date(year, month, 1).end_of_month(), boost::gregorian::Friday);
}

boost::gregorian::date scheduler::last_saturday() const {
    return day_iterator_negative(boost::gregorian::date(year, month, 1).end_of_month(), boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::last_sunday() const {
    return day_iterator_negative(boost::gregorian::date(year, month, 1).end_of_month(), boost::gregorian::Sunday);
}

}  // namespace meetup
