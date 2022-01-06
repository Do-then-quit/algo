def course_selection(course_list):
    if len(course_list) == 0:
        return None
    selec = -1
    for i in course_list:
        if selec == -1:
            selec = i[1]
            selected_course = i
        else:
            if selec > i[1]:
                selec = i[1]
                selected_course = i
    lis_selected_course = [selected_course]
    course_list.remove(selected_course)
    for i in course_list:
        if selected_course[0] <= i[1] <= selected_course[1] or selected_course[0] <= i[0] <= selected_course[1]:
            course_list.remove(i)
            continue
        if i[0] <= selected_course[0] and selected_course[1] <= i[1]:
            course_list.remove(i)
            continue
    if len(course_list) == 0:
        return lis_selected_course
    return lis_selected_course + course_selection(course_list)


# 테스트
print(course_selection([(6, 10), (2, 3), (4, 5), (1, 7), (6, 8), (9, 10)]))
print(course_selection([(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]))
print(course_selection([(4, 7), (2, 5), (1, 3), (8, 10), (5, 9), (2, 5), (13, 16), (9, 11), (1, 8)]))
