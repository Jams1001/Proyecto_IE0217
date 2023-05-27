# Universidad de Costa Rica
## Escuela de Ingeniería Eléctrica
### Estructuras Abstractas de Datos y Algoritmos para Ingeniería
### IE0217
#### Jorge Adán Mora Soto, B95222 
*jorgeadan.mora@ucr.ac.cr*



##### Proyecto IE0217 (Propuesta)
Project in C++. Information systems will be developed where the use of classes and objects will simplify their implementation. Qt will be used, which is a multiplatform framework for software development in C++.

This project consists of the creation of a desktop program developed in C++. It is a timetable MANAGER for a specific school of the University of Costa Rica. Being a timetable manager it includes information about the curriculum of that school, teachers and classrooms. 

> At first glance it looks like it is just as easy as using excel, and it is true. It does not add utility to a real problem. But the goal is to exercise the use of classes and objects, plus it is not limited to lines (as in excel), it also creates objects as such that can be edited and reused in a more user friendly way.


Below you will see the proposed graphical interface that the program will initially have. Please note that this is a **proposal**.



**Home:** First you find the home tab. Just when you open the program, the following window will appear.
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/home0.png)

From here you can edit the University object and the School object. You can only edit their names.

If click on **Teachers:**
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/teachers0.png)


If you click on **Home** in the path above, you will return to Home. This path at the top will be used to navigate through the WHOLE program (something similar to the Windows file explorer).
> There are no "back", "x" or "exit" buttons, only the path. The only way to close the program is from the outside. There will never be a "save" button, all significant changes are asked for confirmation and saved automatically.


Back to home page, if click on **Semesters:**
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters0.png)

If click on **Add** (And this Add button will be the same for ALL objects that have only its name as a characteristic):
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters4.png)

If the name already exists, you will encounter the first error handler:
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters5.png)

But if you click on **Select**:
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters1.png)

If click on **Remove:**
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters2.png)

Back to select page, if click on **Duplicate:**
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters3.png)

> With this option the object will be copied with all its contents and under the same name but adding at the end an (n) (e.g. IS 2024 (1), IIS 2024 (1), IIIS 2024 (1)).

Back to semesters page, if you **double** click on one of those objects:
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6.png)

And you can edit the name of that object.


But if you click (**one click**) on one of those objects, you will see the proposals (so far) of the schedules:
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_0.png)

If you click on the **select** button you will see a new feature called **current schedule**. There can be only one current schedule in the whole program:

![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_1.png)

Then:

![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_2.png)

As soon as you select more than 1 object, the **Current schedule** button will disappear:

![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_3.png)


If you click on one proposal:
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_0_00.png)
> Each line of these is an object called precisely "line". And it contains everything you need to know about the organization of the course in that semester. Also, you can print this timetable guide with the "Print CSV" button to share it later.

If you click on **Add**, you could add new lines:
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_0_0.png)


The objective is that these fields are filled in order. First the _Ciclo_ field and it will show you in a drop down all the courses assigned to that course. When you select the _Sigla_ field, the _Nombre_ and _Dept_ fields will be automatically filled in. Then you will enter the _Grupo_ field, then the _Horario_ field, then the _Cupo_ field, then the _Profesor_ field (where a dropdown will appear with all the registered teachers). Finally,  then you can add extraordinary observations in _Observaciones_ field.


You can also create each of these objects from here. If you don't like any of the dropdown options, you can write a new one and it will be registered in the program main.

And you can find the following error handling messages:

![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_0_1.png)
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_0_2.png)
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_0_3.png)
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/semesters6_0_4.png)


Back to the home window, if you click on **Courses:**
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/courses0.png)
> From here you will not be able to make changes (for now...) You will only be able to see the registered courses.

Back to the home window, if you click on **Classrooms:**
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/classrooms0.png)

Back to the home window, if you click on **Cycles:**
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/cycles0.png)


If you click once one of those:
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/cycles2.png)


Back to cycles, if you click **Add** :
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/cycles3.png)


And you might find the following message: :
![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/cycles4.png)
> It does not matter if the course already exists in this cycle or in some other cycle. If it is repeated, it is repeated.

Finally,  back to the home window, if you click on **External courses:**

![alt text](https://github.com/Jams1001/Proyecto_IE0217/blob/main/images/external_courses0.png)


