#include<iostream>
#include<fstream>
#include<string>
#include<ctime>


using namespace std;

void welcome();
void newacc();
void login();
void editinfo();
void listpatient();
void dischargepatient();
void docadd();
void doclist();
int namecheck(string name);
int roomopdcheck(string roomO);
int roomemgcheck(string roomE);


void welcome()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                 -Presented By FARAZ L1F19BSCS0245     |@@\n";
	cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
	cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
}

void login()
{
	int counter = 5;
	bool flag = false;
	int option;
	int data;
	int variable = 1;
	int variable1;
	int j = 0;
	string read, read1;
	bool flg = false;
	bool flag2 = false;
	string nameop;
	string idop;
	/*string words[1000];*/
	int search;
	int count = 0;
	string nameO, ageO, disO, nameE, ageE, disE,docO,docE;
	string roomO; int idO; string roomE; int idE;
	char sexO, sexE;
	fstream folder, folder1;
	fstream room;
	fstream room1;
	string name;
	string loginname;
	string loginpass;
	string password;
	string nameem;
	string idem;
	int select = 0;
	do
	{
		cout << "\n\n\                                       LOGIN PAGE                               \n";
		cout << "------------------------------------------------------------------------------------------";

		cout << "\nPress 1>> For Login\n\n\nPress 2>> For SignUp\n\n\n";
		cout << "PRess 3>> To Exit Program\n\n\n";
		cout << ">>>"; cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "NOTE:\t\t\t\t\t\t THERE ARE ONLY 5 TRIES TO LOGIN:\n\n\n\n";
			cout << "\nEnter USername:";
			cout << "\n>>"; cin >> name;
			cout << "\nENter Password";
			cout << "\n>>"; cin >> password;
			fstream file;
			file.open("Users.txt", ios::in);
			if (file)
			{
				while (!file.eof())
				{
					file >> loginname;
					file >> loginpass;
					if (loginname == name && loginpass == password)
					{
						flag = true;
					}
				}
				if (flag == true)
				{
					cout << "\n>>>> Access granted\nLogined Succesfull-----\n\n";
					do
					{
						variable1 = 1;
						cout << "\n*********************MAIN MEMU*************************\n";
						cout << "\n*******************************************************\n";
						cout << "   Choose the option What to do:\n\n\n";
						cout << "1. Add patient record\n"; cout << endl;
						cout << "2. Search or edit PAtient Record\n"; cout << endl;
						cout << "3. List of record of PAtients\n"; cout << endl;
						cout << "4. DISCHARGE The Patient\n"; cout << endl;
						cout << "5. ADD DOCTOR Details\n"; cout << endl;
						cout << "6. Logout To continue to Login Page\n" << endl;
						cout << "\n*******************************************************\n";
						cout << ">>>";
						cin >> option;
						if (option == 1)
						{
							cout << "Enter '1' To ADD OPD PATEINT RECORD"; cout << " OR\n"; cout << endl << endl;
							cout << "Enter -1 TO ADD EMERGENCY PATIENT RECORD\n"; cout << endl << endl;
							cout << ">>>"; cin >> data; cout << endl;

							switch (data)
							{
							case 1:
							{
								while (variable1 != 0)
								{
									

									cout << "\t\tTHIS IS OPD SREVICE OF HOSPITAL\n"; cout << endl;
									cout << "\t\t---------------------------------------------\n"; cout << endl;

									cout << "PLEASE ENTER DOCTOR NAME:";
									cin >> docO; cout << endl << endl;
									fstream doc;
									string doc_O;
									int countii = 0;
									doc.open("docprofile.txt", ios::in);
									if (doc)
									{
										while (!doc.eof())
										{
											getline(doc, doc_O);
											countii++;
										}
										doc.close();
										string* docopd = new string[countii];



										doc.open("docprofile.txt", ios::in);
										for (int k = 0; k < countii; k++)
										{
											doc >> docopd[k];
										}
										doc.close();
										bool docflag = false;
										for (int k = 0; k < countii; k++)
										{
											if (docopd[k] == docO)
											{
												docflag = true;
											}
										}
											if (docflag == true)
											{
											

												cout << "Enter PAtient Name:";
												cin >> nameO; cout << endl; cout << endl;
												cout << "PAtient iD:";
												cin >> idO;
												cout << idO; cout << endl; cout << endl;
												cout << "ENter Patient AGe:";
												cin >> ageO; cout << endl; cout << endl;
												cout << "ENter PAtient GEnder: (f/m)";
												cin >> sexO; cout << endl; cout << endl;
												while (sexO != 'm' && sexO != 'M' && sexO != 'F' && sexO != 'f')
												{
													cout << "PLease enter correct gender again:"; cin >> sexO;
												}
												cout << endl; cout << endl;
												cout << "ENter Disease Name:";
												cin >> disO; cout << endl; cout << endl;

												cout << "ENTER ROOM NO:";
												cin >> roomO;

												room.open("roomsopd.txt", ios::in);

												if (room)
												{
													int res1 = roomopdcheck(roomO);
													while (res1 == 1)
													{
														cout << "\nTHIS ROOM IS ALREADY OCCUPIED";
														cout << "\nENTER NEW ROOM\n";
														cin >> roomO;
														res1 = roomopdcheck(roomO);
													}
													room.open("roomsopd.txt", ios::out | ios::app);
													room << roomO << endl;
													room.close();
													folder.open("opdpatientinfo.txt", ios::out | ios::app);
													folder << nameO << " " << idO << " " << ageO << " " << sexO << " " << disO << " " << docO << " " << roomO << endl;
													folder.close();
												}
												else
												{
													room.open("roomsopd.txt", ios::out | ios::app);
													folder.open("opdpatientinfo.txt", ios::out | ios::app);
													folder << nameO << " " << idO << " " << ageO << " " << sexO << " " << disO << " " << docO << " " << roomO << endl;
													room << roomO << endl;
													room.close();
													folder.close();
												}

												/*room.close();*/
												/*while (variable1 != 0)
												{*/

												/*}*/
												/*bool roomflag = true;*/
												//room.open("roomsopd.txt", ios::in);
												///*int door = 0;*/
												//if (room)
												//{
												//	string readi;
												//	while (roomflag == true)
												//	{
												//		room.open("roomsopd.txt", ios::in);
												//		cout << "ENTER ROOM NO:"; cin >> roomO;
												//		while (!room.eof())
												//		{
												//			room >> readi;
												//			if (roomO == readi)
												//			{
												//				cout << "\nTHE ROOM YOU ENTERED IS OCCUPIED\n";
												//				cout << "\nENTER NEW ROOM NO\n";
												//				roomflag = true;
												//				break;
												//			}
												//			else
												//			{
												//				roomflag = false;
												//			}
												//			/*getline(room, readi);
												//			door++;*/
												//		}
												//		room.close();
												//	}
												//}
												//else
												//{
												//	cout << "ENTER ROOM NO:"; cin >> roomO;
												//}
											 // 	room.close();
												/*string* roomfile = new string[door];
												room.open("roomsopd.txt", ios::in);
												if (room)
												{
													
													while (!room.eof())
													{
														for (int k = 0; k < door; k++)
														{
															room >> roomfile[k];
														}
													}
												}*/

												
												/* bool condition = false;*/
												/*if (room)
												{
													for (int k = 0; k < door; k++)
													{
														if (roomO[i] == roomfile[k])
														{
															cout << "This is occupied:\n" << endl;
															cout << "Enter room again:\n";
															cout << ">>>"; cin >> roomO[i];
														}
													}
												}
												room.close();
												for (int counter = 0; counter < i; counter++)
												{
													if (roomO[i] == roomO[counter])
													{
														cout << "\nThis is occupied:\n" << endl;
														cout << "\nEnter room again:\n";
														cin >> roomO[i];
													}
												}*/
												


												cout << "Press 0 for main menu && 1 for TO ADD:";
												cin >> variable1;
												while (variable1 < 0 || variable1>1)
												{
													cout << "Now Press 0 for main menu:";
													cin >> variable1;
												}
												
												/*i++;*/






											}
										/*}*/
										if (docflag == false)
										{
											cout << "\n\nDOCTOR PROFILe NOT FOUND\n\n";
											cout << "\nProceed To MAin MENU TO ADD DOCTOR PROFILE\n\n";
											cout << "Press 0 for main menu AND 1 to Add AGAin";
											cin >> variable1;
											while (variable1 < 0 || variable1>1)
											{
												cout << "Now Press 0 for main menu:";
												cin >> variable1;
											}
										}
										delete[]docopd;

									}
									else
									{
										cout << "\n\nDOCTOR PROFILE FILE DOESNOT EXIST\n\n";
										cout << "\nPRESS 0 for MAin MENU TO CREATE DOCTOR PROFILE\n\n";
										cout << "Press 0 for main menu And 1 To add again";
										cin >> variable1;
										while (variable1 < 0 || variable1 > 1)
										{
											cout << "Now Press 0 for main menu:";
											cin >> variable1;
										}
									}



									
								}
								
								

							}break;
							case -1:
							{
								while (variable1 != 0)
								{
									
									

									cout << "\t\tTHIS IS EMERGENCY SREVICE\t\t\n"; cout << endl;
									cout << "\t---------------------------------------------\n"; cout << endl;

									cout << "PLEASE ENTER DOCTOR NAME:";
									cin >> docE; cout << endl << endl;
									fstream doc1;
									string doc_O1;
									int countii1 = 0;
									doc1.open("docprofile.txt", ios::in);

									if (doc1)
									{
										while (!doc1.eof())
										{
											getline(doc1, doc_O1);
											countii1++;
										}
										doc1.close();
										string* docemg = new string[countii1];



										doc1.open("docprofile.txt", ios::in);
										for (int k = 0; k < countii1; k++)
										{
											doc1 >> docemg[k];
										}
										doc1.close();
										bool docflag1 = false;
										for (int k = 0; k < countii1; k++)
										{
											if (docemg[k] == docE)
											{
												docflag1 = true;
											}
										}
											if(docflag1==true)
											{
												cout << "Enter PAtient Name:";
												cin >> nameE; cout << endl; cout << endl;
												cout << "PAtient iD:";
												/*idE = j + 1;*/
												cin >> idE;
												cout << idE; cout << endl; cout << endl;
												cout << "ENter Patient AGe:";
												cin >> ageE; cout << endl; cout << endl;
												cout << "ENter PAtient GEnder: (f/m)";
												cin >> sexE; cout << endl; cout << endl;
												while (sexE != 'm' && sexE != 'M' && sexE != 'F' && sexE != 'f')
												{
													cout << "PLease enter correct gender again:"; cin >> sexE;
												}
												cout << endl; cout << endl;
												cout << "ENter Disease Name:";
												cin >> disE; cout << endl; cout << endl;

												cout << "ENTER BED NO:";
												cin >> roomE;

												room1.open("roomsemg.txt", ios::in);

												if (room1)
												{
													int res2 = roomemgcheck(roomE);
													while (res2 == 1)
													{
														cout << "\nTHIS BED IS ALREADY OCCUPIED";
														cout << "\nENTER NEW ROOM\n";
														cin >> roomE;
														res2 = roomemgcheck(roomE);
													}
													room1.open("roomsemg.txt", ios::out | ios::app);
													room1 << roomE << endl;
													room1.close();
													folder1.open("emgpatientinfo.txt", ios::out | ios::app);
													folder1 << nameE << " " << idE << " " << ageE << " " << sexE << " " << disE << " " << docE << " " << roomE << endl;
													folder1.close();
												}
												else
												{
													room1.open("roomsemg.txt", ios::out | ios::app);
													folder1.open("emgpatientinfo.txt", ios::out | ios::app);
													folder1 << nameE << " " << idE << " " << ageE << " " << sexE << " " << disE << " " << docE << " " << roomE << endl;
													room1 << roomE << endl;
													room1.close();
													folder1.close();
												}




												/*int door1 = 0;*/
												
												//bool roomflag1 = true;
												//room1.open("roomsemg.txt", ios::in);
												//if (room1)
												//{
												//	string readi1;
												//	while (roomflag1 == true)
												//	{
												//		room1.open("roomsemg.txt", ios::in);
												//		cout << "ENTER BED NO:";
												//		cin >> roomE;
												//		while (!room1.eof())
												//		{
												//			room1 >> readi1;
												//			if (roomE == readi1)
												//			{
												//				cout << "\nTHE BED YOU ENTERED IS OCCUPIED\n";
												//				cout << "\nENTER NEW BED NO\n";
												//				roomflag1 = true;
												//				break;
												//			}
												//			else
												//			{
												//				roomflag1 = false;
												//			}
												//			/*getline(room1, readi1);
												//			door1++;*/
												//		}
												//		room1.close();
												//	}
												//}
												//else
												//{
												//	cout << "ENTER BED NO:"; cin >> roomE;
												//}
												//room1.close();
												/*string* roomfile1 = new string[door1];
												room1.open("roomsemg.txt", ios::in);
												while (!room1.eof())
												{
													for (int k = 0; k < door1; k++)
													{
														room1 >> roomfile1[k];
													}
												}*/
												/*room1.close();*/
												
												/*for (int k = 0; k < door1; k++)
												{
													while (roomE[j] == roomfile1[k])
													{
														cout << "This is occupied:\n" << endl;
														cout << "Enter room again\n";
														cout << ">>>"; cin >> roomE[j];
													}
												}
												for (int counter = 0; counter < j; counter++)
												{
													while (roomE[j] == roomE[counter])
													{
														cout << "this is occupied:";
														cout << "Enter Bed NO again:";
														cout << ">>>"; cin >> roomE[j];
													}
												}*/

												/*folder1.open("emgpatientinfo.txt", ios::out | ios::app);
												room1.open("roomsemg.txt", ios::out | ios::app);
												folder1 << nameE << " " << idE << " " << ageE << " " << sexE << " " << disE << " " << docE << " " << roomE << endl;
												room1 << roomE << endl;
												room1.close();
												folder1.close();*/


												cout << "Press 0 for main menu && 1 for TO ADD:";
												cin >> variable1;
												while (variable1 < 0 || variable1>1)
												{
													cout << "Now Press 0 for main menu:";
													cin >> variable1;
												}
												
											}
										/*}*/
										if (docflag1 == false)
										{
											cout << "\n\nDOCTOR PROFILe NOT FOUND\n\n";
											cout << "\nProceed To MAin MENU TO ADD DOCTOR PROFILE\n\n";
											cout << "Press 0 for main menu AND 1 to Add AGAin";
											cin >> variable1;
											while (variable1 < 0 || variable1>1)
											{
												cout << "Now Press 0 for main menu:";
												cin >> variable1;
											}
										}
										delete[]docemg;
									}
									else
									{
										cout << "\n\nDOCTOR PROFILE FILE DOESNOT EXIST\n\n";
										cout << "\nPRESS 0 for MAin MENU TO CREATE DOCTOR PROFILE\n\n";
										cout << "Press 0 for main menu And 1 To add again";
										cin >> variable1;
										while (variable1 < 0 || variable1 > 1)
										{
											cout << "Now Press 0 for main menu:";
											cin >> variable1;
										}
									}
								}
								
							}break;
							default:
							{
								cout << "Inavlid INput" << endl;
								cout << "Press 0 for main menu:";
								cin >> variable1;
								while (variable1 < 0 || variable1>0)
								{
									cout << "Press 0 for main menu";
									cin >> variable1;
								}
							}
							}


						}
						else if (option == 2)
						{
							while (variable1 != 0)
							{
								cout << "Choose 0ption What TO DO:"; cout << endl;
								cout << "Press>> 1 To SEARCH" << endl;
								cout << "Press>> 2 To edit" << endl;
								cout << "Press 0 For main menu" << endl;
								cout << ">>> "; cin >> search;
								switch (search)
								{
								case 1:
								{
									cout << "Choose option:"; cout << endl;
									cout << "Enter 1 to OPD SEARCH & 2 To EMERGENCY SEARCH:";
									cin >> data; cout << endl;
									if (data == 1)
									{
										cout << "\nEnter Name To Search:\n";
										cout << ">>>"; cin >> nameop;
										cout << "\nENTER PAtient Id to Search:\n";
										cout << ">>>"; cin >> idop;
										fstream file1;
										file1.open("opdpatientinfo.txt", ios::in);
										if (file1)
										{
											while (!file1.eof())
											{
												getline(file1, read);
												count++;
											}
										}
										else
										{
											cout << "\n\nFILe nOT FOUND\n\n";
										}
										file1.close();
										string* nameopd = new string[count];
										string* idopd = new string[count];
										string* ageopd = new string[count];
										string* genderopd = new string[count];
										string* disopd = new string[count];
										string* docopd = new string[count];
										string* roomopd = new string[count];
										file1.open("opdpatientinfo.txt", ios::in);
										if (file1)
										{
											while (!file1.eof())
											{
												for (int k = 0; k < count; k++)
												{
													file1 >> nameopd[k];
													file1 >> idopd[k];
													file1 >> ageopd[k];
													file1 >> genderopd[k];
													file1 >> disopd[k];
													file1 >> docopd[k];
													file1 >> roomopd[k];
												}
											}
										}
										file1.close();
										for (int k = 0; k < count; k++)
										{
											if (nameopd[k] == nameop && idopd[k] == idop)
											{
												flg = true;
												cout << "Name: " << nameopd[k] << endl;
												cout << "iD: " << idopd[k] << endl;
												cout << "age: " << ageopd[k] << endl;
												cout << "Gender: " << genderopd[k] << endl;
												cout << " Disease: " << disopd[k] << endl;
												cout << "DOCTOR NAME:" << docopd[k] << endl;
												cout << "Room NO: " << roomopd[k] << endl;
												cout << endl;
											}
										}
										if (flg == false)
										{
											cout << "\nRESPECTIVE PATIENT RECORD NOT FOUND\n";
										}
										delete[]nameopd;
										delete[]idopd;
										delete[]ageopd;
										delete[]genderopd;
										delete[]disopd;
										delete[]docopd;
										delete[]roomopd;

									}
									else if (data == 2)
									{
										cout << "\nEnter Name To Search:\n";
										cin >> nameem;
										cout << "\nENTER PAtient Id to Search:\n";
										cin >> idem;

										int count1 = 0;

										fstream file2;

										file2.open("emgpatientinfo.txt", ios::in);
										/*if (!file2)
										{
											cout << "\nyes\n";
										}*/
										if (file2)
										{
											while (!file2.eof())
											{
												getline(file2, read1);
												count1++;
											}
										}
										else
										{
											cout << "\n\nFILE NOT FOUND\n\n";
										}
										file2.close();

										string* nameemg = new string[count1];
										string* idemg = new string[count1];
										string* ageemg = new string[count1];
										string* genderemg = new string[count1];
										string* disemg = new string[count1];
										string* docemg = new string[count1];
										string* roomemg = new string[count1];
										file2.open("emgpatientinfo.txt", ios::in);
										/* if (file2)
										 {
											 cout << "\nyes\n";
										 }*/

										if (file2)
										{
											while (!file2.eof())
											{
												for (int k = 0; k < count1; k++)
												{
													file2 >> nameemg[k];
													file2 >> idemg[k];
													file2 >> ageemg[k];
													file2 >> genderemg[k];
													file2 >> disemg[k];
													file2 >> docemg[k];
													file2 >> roomemg[k];
												}
											}
										}
										else
										{
											cout << "\n\nRECORD NOT FOUND\n\n";
										}
										file2.close();
										for (int k = 0; k < count1; k++)
										{
											if (nameemg[k] == nameem && idemg[k] == idem)
											{
												flag2 = true;
												cout << "Name: " << nameemg[k] << endl;
												cout << "iD: " << idemg[k] << endl;
												cout << "age: " << ageemg[k] << endl;
												cout << "Gender: " << genderemg[k] << endl;
												cout << "Disease: " << disemg[k] << endl;
												cout << "DOCTOR NAME:" << docemg[k] << endl;
												cout << "BED NO: " << roomemg[k] << endl;
												cout << endl;
											}
										}
										if (flag2 == false)
										{
											cout << "\nRESPECTIVE PATIENT Record NOT FOUND\n";
										}

										delete[]nameemg;
										delete[]idemg;
										delete[]ageemg;
										delete[]genderemg;
										delete[]disemg;
										delete[]docemg;
										delete[]roomemg;
									}

								}break;
								case 2:
								{
									editinfo();
								}break;
								case 0:
								{
									variable1 = 0;
								}break;
								default:
								{
									cout << "Inavlid INput" << endl;
									cout << "Press 0 for main menu:";
									cin >> variable1;
									while (variable1 < 0 || variable1>0)
									{
										cout << "Press 0 for main menu";
										cin >> variable1;
									}
								}
								}
							}
						}
						else if (option == 3)
						{
							while (variable1 != 0)
							{
								int list1;
								cout << "\n\nPRESS 1 For LIST\n\n";
								cout << "\n\nPRESS 0 For Main menu\n";
								cout << ">>>"; cin >> list1;
								switch (list1)
								{
								case 1:
								{
									listpatient();
								}break;
								case 0:
								{
									variable1 = 0;
								}break;
								default:
								{
									cout << "Inavlid INput" << endl;
									cout << "Press 0 for main menu:";
									cin >> variable1;
									while (variable1 < 0 || variable1>0)
									{
										cout << "Press 0 for main menu";
										cin >> variable1;
									}
								}
								}

							}
						}
						else if (option == 4)
						{
							while (variable1 != 0)
							{

								/*  dischargepatient();*/


								int discharge;
								cout << "\n\nPRESS 1>> For DIscharge  \n\n";
								cout << "\n\nPRESS 0>> For Main menu\n";
								cout << ">>>"; cin >> discharge;
								switch (discharge)
								{
								case 1:
								{
									dischargepatient();
								}break;
								case 0:
								{
									variable1 = 0;
								}break;
								default:
								{
									cout << "Inavlid INput" << endl;
									cout << "Press 0 for main menu:";
									cin >> variable1;
									while (variable1 < 0 || variable1>0)
									{
										cout << "Press 0 for main menu";
										cin >> variable1;
									}
								}
								}


							}
						}
						else if (option == 5)
						{
							while (variable1!=0)
							{
								int docchoice;
								cout << "\n\nPRESS 1. TO ADD DOCTOR DETAILS\n\n";
								cout << "\n\nPRESS 2.TO SHOW LIST OF THE DOCTORS\n\n";
								cout << "\n\nPRESS 0. TO CONTNUE TO MAIN MENU\n\n";
								cout << ">>>"; cin >> docchoice;
								switch (docchoice)
								{
								case 1:
								{
									docadd();
								}break;
								case 2:
								{
									doclist();
								}break;
								case 0:
								{
									variable1 = 0;
								}break;
								default:
								{
									cout << "Inavlid INput" << endl;
									cout << "Press 0 for main menu:";
									cin >> variable1;
									while (variable1 < 0 || variable1>0)
									{
										cout << "Press 0 for main menu";
										cin >> variable1;
									}
								}
								}
							}
                        }
						else if (option == 6)
						{
							variable = 1;
						}
						else if(option>6||option<1)
						{
						 cout << "\nYOU EnTERED WRONG INPUT";
						 cout << "\n\REDIRECTING TO MAIN MENU\n";
						   variable1 = 0;
                        }
					} while (variable1 == 0);
					cout << "\n\nMAIN MENU:";
					/* variable = 0;*/
				}
				else
				{
					cout << "\n>>>>> Error During Login..........\n\n";
					cout << "\n\nLogin Error.......\n";
					variable = 1;
					counter--;
					cout << counter << " Times Left to login";
					cout << "\n\nTRY AGAIN\n\n";
				}
				if (counter <= 0)
				{
					variable = 0;
				}
			}
			else
			{
			  cout << "\n\nNO SUCH FILE EXIST OF USER PROFILES\n\n";
			  cout << "\n\nPROCEEDING TO LOGIN PAGE AND ADD A PROFILE TO LOGIN\n\n";
			  variable = 1;
            }
		}
		break;
		case 2:
		{
			newacc();
			variable = 1;
		}
		break;
		case 3:
		{
			variable = 0;
		}break;
		default:
		{
			/*if (select != 1 || select != 2)
			{*/
		
			while (select > 3 || select < 2)
			{
				cout << "\n\n------Failed-------";
				cout << "\nYOU ENTERED WRONG INPUT\n";
				cout << "\nPress 2 To Contiue to Login Page";
				cout << "\nOR\nPRESS 3 TO EXIT THE PROGRAM\n";
				/*cout << "\n\nPlease Enter The Required INput\n";
				cout << "Press 1>> For Login\nPress 2>> For SignUp\n";*/
				/*cout << "PRess 3>> To Exit Program\n\n\n";*/
				cout << ">>>"; cin >> select;
				if (select == 3)
				{
					variable = 0;
				}
				else
				{
					variable = 1;
				}
			/*}*/

			}
		}
		}
	} while (variable == 1);
	if (variable == 0 && counter <= 0)
	{
		cout << "\n\nToooo MANY TIMES Tried to Log in\n";
		cout << "\n\n\nSYSTEM WILL SHOUT DOWN NOW.....\n\n";
	}
	cout << "\n---------------------------------------------------------------\n";
	cout << "\n\n\nThank You For Using The Program :)\n\n\n";
	cout << "\n\nHOPE YOU ENJOY THE SOFTWARE\n";
	cout << "----------------------------------------------------------------\n";
}

void editinfo()
{
	int variable1;
	int edit;
	cout << "\nPRESs 1. EDIT OPD PATIENT INFO\n";
	cout << "Press 2. EDIT EMERGENCY PATIENT INFo\n";
	cin >> edit;
	if (edit == 1)
	{
		int l;
		string doccheck;
		int variable1;
		int count3 = 0;
		string reading;
		fstream filing;
		filing.open("opdpatientinfo.txt", ios::in);
		if (filing)
		{
			while (!filing.eof())
			{
				getline(filing, reading);
				count3++;
			}
		}
		else
		{
			cout << "\n\nFILE NOT FOUND\n\n";
		}
		filing.close();
		string* nameopd1 = new string[count3];
		string* idopd1 = new string[count3];
		string* ageopd1 = new string[count3];
		string* genderopd1 = new string[count3];
		string* disopd1 = new string[count3];
		string* docopd1 = new string[count3];
		string* roomopd1 = new string[count3];
		string nameop1;
		string idop1;
		bool condition = false;
		bool docflag = false;
		filing.open("opdpatientinfo.txt", ios::in);
		if (filing)
		{
			while (!filing.eof())
			{
				for (int k = 0; k < count3; k++)
				{
					filing >> nameopd1[k];
					filing >> idopd1[k];
					filing >> ageopd1[k];
					filing >> genderopd1[k];
					filing >> disopd1[k];
					filing >> docopd1[k];
					filing >> roomopd1[k];
				}
			}




			cout << "\nPlease ENTER NAME OF PATIENT TO EDIT RECORD:\n";
			cout << ">>>"; cin >> nameop1;
			cout << "\nPLEASE ENTER ID OF THE PaTiENT TO EDIT RECORD:\n";
			cout << ">>>"; cin >> idop1;
		}
		else
		{
			cout << "\n\nFILE DOESNOT EXIST\n\n";
		}
		filing.close();
		int which;
		for (int k = 0; k < count3; k++)
		{
			if (nameopd1[k] == nameop1 && idopd1[k] == idop1)
			{
				condition = true;
				cout << "\nPRESS 1. TO EDIT NAME\n";
				cout << "\nPRESS 2. TO EDIT AGE\n";
				cout << "\nPRESS 3. TO EDIT ID\n";
				cout << "\nPRESS 4. TO EDIT GENDER\n";
				cout << "\nPRESS 5. TO EDIT DISEASE NAME\n";
				cout << "\nPRESS 6. TO EDIT DOCTORS NAME\n";
				cout << "\nPRESS 7. TO EDIT ROOM NO\n";
				cout << ">>> "; cin >> which;
				switch (which)
				{
				case 1:
				{
					cout << "\nENTER NEW NAME:\n";
					cin >> nameopd1[k];
				}
				break;
				case 2:
				{
					cout << "\nENTER NEW AGE:\n";
					cin >> ageopd1[k];
				}
				break;
				case 3:
				{
					cout << "\nENTER NEW ID:\n";
					cin >> idopd1[k];
				}
				break;
				case 4:
				{
					cout << "\nENTER NEW GENDER:(f/m)\n";
					cin >> genderopd1[k];
				}
				break;
				case 5:
				{
					cout << "\nENTER NEW DISEASE NAME:\n";
					cin >> disopd1[k];
				}
				break;
				case 6:
				{
					
					cout << "\nENTER NEW DOCTORS NAME:\n";
					cin >> doccheck;
					l = k;
					fstream doc;
					string doc_O;
					int countii = 0;
					doc.open("docprofile.txt", ios::in);

					if (doc)
					{
						while (!doc.eof())
						{
							getline(doc, doc_O);
							countii++;
						}
						doc.close();
						string* docopd = new string[countii];



						doc.open("docprofile.txt", ios::in);
						for (int x = 0; x < countii; x++)
						{
							doc >> docopd[x];
						}
						doc.close();
						

						for (int x = 0; x < countii; x++)
						{
							if (docopd[x] ==doccheck)
							{
								docflag = true;
								/*filing.close();*/
							}
						}
						if (docflag == false)
						{
							cout << "\n\nDOCTOR PROFILe NOT FOUND\n\n";
							cout << "\nProceed To MAin MENU TO ADD DOCTOR PROFILE\n\n";
							cout << "Press 0 for main menu AND 1 to Add AGAin";
							cin >> variable1;
							while (variable1 < 0 || variable1>1)
							{
								cout << "Now Press 0 for main menu:";
								cin >> variable1;
							}
						}

					}
					else
					{
						cout << "\n\nDOCTOR PROFILE FILE DOESNOT EXIST\n\n";
						cout << "\nPRESS 0 for MAin MENU TO CREATE DOCTOR PROFILE\n\n";
						cout << "Press 0 for main menu And 1 To add again";
						cin >> variable1;
						while (variable1 < 0 || variable1 > 1)
						{
							cout << "Now Press 0 for main menu:";
							cin >> variable1;
						}
					}
				}break;
				case 7:
				{
					cout << "\nENTER NEW ROOM NO:\n";
					cin >> roomopd1[k];
				}
				break;

				default:
				{
					cout << "\nInavlid INput\n" << endl;
					cout << "\nPRESS 0 for Main MENU\n";
					cin >> variable1;
					while (variable1 < 0 || variable1>0)
					{
						cout << "Press 0 for main menu";
						cin >> variable1;
					}
				}
				}
			}
		}
		if (condition == false)
		{
			cout << "\n\nRespective Patient Is not Present\n\n";
		}
		
		if (docflag == false)
		{
			filing.open("opdpatientinfo.txt", ios::out);
			for (int k = 0; k < count3; k++)
			{

				filing << nameopd1[k] << " ";
				filing << idopd1[k] << " ";
				filing << ageopd1[k] << " ";
				filing << genderopd1[k] << " ";
				filing << disopd1[k] << " ";
				filing << docopd1[k] << " ";
				filing << roomopd1[k] << " ";

				if (k != count3 - 1)
				{
					filing << endl;
				}
				cout << "\n\nPATIENT RECORD EDITED SUCCESFULLY\n\n";

			}
		}
		if (docflag == true)
		{
			docopd1[l] = doccheck;
			filing.open("opdpatientinfo.txt", ios::out);
			for (int y = 0; y < count3; y++)
			{

				filing << nameopd1[y] << " ";
				filing << idopd1[y] << " ";
				filing << ageopd1[y] << " ";
				filing << genderopd1[y] << " ";
				filing << disopd1[y] << " ";
				filing << docopd1[y] << " ";
				filing << roomopd1[y] << " ";

				if (y != count3 - 1)
				{
					filing << endl;
				}
			}
			cout << "\n\nPATIENT RECORD EDITED SUCCESFULLY\n\n";
		}
		filing.close();

		delete[]nameopd1;
		delete[]idopd1;
		delete[]ageopd1;
		delete[]genderopd1;
		delete[]disopd1;
		delete[]docopd1;
		delete[]roomopd1;


	}
	else if (edit == 2)
	{
	     int l1;
	    string doccheck1;
		int variable2;
		int count4 = 0;
		string reading1;
		fstream filing1;
		filing1.open("emgpatientinfo.txt", ios::in);
		if (filing1)
		{
			while (!filing1.eof())
			{
				getline(filing1, reading1);
				count4++;
			}
		}
		else
		{
			cout << "\n\nFILE DOESNOT EXIST\n\n";
		}
		filing1.close();
		string* nameemg1 = new string[count4];
		string* idemg1 = new string[count4];
		string* ageemg1 = new string[count4];
		string* genderemg1 = new string[count4];
		string* disemg1 = new string[count4];
		string* docemg1 = new string[count4];
		string* roomemg1 = new string[count4];
		string nameem1;
		string idem1;
		bool condition1 = false;
		bool docflag1 = false;
		filing1.open("emgpatientinfo.txt", ios::in);
		if (filing1)
		{
			while (!filing1.eof())
			{
				for (int k = 0; k < count4; k++)
				{
					filing1 >> nameemg1[k];
					filing1 >> idemg1[k];
					filing1 >> ageemg1[k];
					filing1 >> genderemg1[k];
					filing1 >> disemg1[k];
					filing1 >> docemg1[k];
					filing1 >> roomemg1[k];
				}
			}




			cout << "\nPlease ENTER NAME OF PATIENT TO EDIT RECORD:\n";
			cout << ">>>"; cin >> nameem1;
			cout << "\nPLEASE ENTER ID OF THE PaTiENT TO EDIT RECORD:\n";
			cout << ">>>"; cin >> idem1;
		}
		else
		{
			cout << "\n\nFILE DOESNOT EXIST\n\n";
		}
		filing1.close();
		int which1;
		for (int k = 0; k < count4; k++)
		{
			if (nameemg1[k] == nameem1 && idemg1[k] == idem1)
			{
				condition1 = true;
				cout << "\nPRESS 1. TO EDIT NAME\n";
				cout << "\nPRESS 2. TO EDIT AGE\n";
				cout << "\nPRESS 3. TO EDIT ID\n";
				cout << "\nPRESS 4. TO EDIT GENDER\n";
				cout << "\nPRESS 5. TO EDIT DISEASE NAME\n";
				cout << "\nPRESS 6. TO EDIT DOCTORS NAME\n";
				cout << "\nPRESS 7. TO EDIT ROOM NO\n";
				cout << ">>> "; cin >> which1;
				switch (which1)
				{
				case 1:
				{
					cout << "\nENTER NEW NAME:\n";
					cin >> nameemg1[k];
				}
				break;
				case 2:
				{
					cout << "\nENTER NEW AGE:\n";
					cin >> ageemg1[k];
				}
				break;
				case 3:
				{
					cout << "\nENTER NEW ID:\n";
					cin >> idemg1[k];
				}
				break;
				case 4:
				{
					cout << "\nENTER NEW GENDER:(f/m)\n";
					cin >> genderemg1[k];
				}
				break;
				case 5:
				{
					cout << "\nENTER NEW DISEASE NAME:\n";
					cin >> disemg1[k];
				}
				break;
				case 6:
				{
					cout << "\nENTER NEW DOCTORS NAME:\n";
					cin >> doccheck1;
					l1 = k;

					fstream doc1;
					string doc_O1;
					int countii1 = 0;
					doc1.open("docprofile.txt", ios::in);

					if (doc1)
					{
						while (!doc1.eof())
						{
							getline(doc1, doc_O1);
							countii1++;
						}
						doc1.close();

						string* docemg = new string[countii1];



						doc1.open("docprofile.txt", ios::in);
						for (int x = 0; x < countii1; x++)
						{
							doc1 >> docemg[x];
						}
						doc1.close();


						for (int x = 0; x < countii1; x++)
						{
							if (docemg[x] == doccheck1)
							{
								docflag1 = true;
								/*filing.close();*/
							}
						}
					}
					else
					{
						cout << "\n\nDOCTOR PROFILE FILE DOESNOT EXIST\n\n";
						cout << "\nPRESS 0 for MAin MENU TO CREATE DOCTOR PROFILE\n\n";
						cout << "Press 0 for main menu And 1 To add again";
						cin >> variable1;
						while (variable1 < 0 || variable1 > 1)
						{
							cout << "Now Press 0 for main menu:";
							cin >> variable1;
						}
					}

				}break;
				case 7:
				{
					cout << "\nENTER NEW ROOM NO:\n";
					cin >> roomemg1[k];
				}
				break;

				default:
				{
					cout << "\nInavlid INput\n" << endl;
					cout << "\nPRESS 0 for Main MENU\n";
					cin >> variable2;
					while (variable2 < 0 || variable2>0)
					{
						cout << "Press 0 for main menu";
						cin >> variable2;
					}
				}
				}
			}
		}
		if (condition1 == false)
		{
			cout << "\n\nRespective Patient Record Not Found\n\n";
		}
		if (docflag1 == false)
		{
			filing1.open("emgpatientinfo.txt", ios::out);
			for (int k = 0; k < count4; k++)
			{

				filing1 << nameemg1[k] << " ";
				filing1 << idemg1[k] << " ";
				filing1 << ageemg1[k] << " ";
				filing1 << genderemg1[k] << " ";
				filing1 << disemg1[k] << " ";
				filing1 << docemg1[k] << " ";
				filing1 << roomemg1[k] << " ";
				if (k != count4 - 1)
				{
					filing1 << endl;
				}

				cout << "\n\nPATIENT RECORD EDITED SUCCESFULLY\n\n";

			}
		}
		if (docflag1 == true)
		{
			docemg1[l1] = doccheck1;
			filing1.open("emgpatientinfo.txt", ios::out);
			for (int y = 0; y < count4; y++)
			{

				filing1 << nameemg1[y] << " ";
				filing1 << idemg1[y] << " ";
				filing1 << ageemg1[y] << " ";
				filing1 << genderemg1[y] << " ";
				filing1 << disemg1[y] << " ";
				filing1 << docemg1[y] << " ";
				filing1 << roomemg1[y] << " ";

				if (y != count4 - 1)
				{
					filing1 << endl;
				}
				cout << "\n\nPATIENT RECORD EDITED SUCCESFULLY\n\n";
			}
		}
		filing1.close();
		delete[]nameemg1;
		delete[]idemg1;
		delete[]ageemg1;
		delete[]genderemg1;
		delete[]disemg1;
		delete[]docemg1;
		delete[]roomemg1;
	}
}
void listpatient()
{
	int variable1;
	int list;
	cout << "\n\nPress 1. LIST OF OPD PATIENTS\n\n";
	cout << "\n\nPress 2. LIST OF EMERGENCY PATIENTS\n\n";
	cout << "\n\nPRess 3. LIST OF DISCHARGE PATIENTS\n\n";
	cout << ">>>"; cin >> list;

	switch (list)	                 /*if (list == 1)*/
	{
	case 1:
	{

		int count3 = 0;
		string reading;
		fstream filing;
		filing.open("opdpatientinfo.txt", ios::in);
		if (filing)
		{
			while (!filing.eof())
			{
				getline(filing, reading);
				count3++;
			}
		}
		else
		{
			cout << "\n\nNO RECORD FOUND\n\n";
		}
		filing.close();
		string* nameopd1 = new string[count3];
		string* idopd1 = new string[count3];
		string* ageopd1 = new string[count3];
		string* genderopd1 = new string[count3];
		string* disopd1 = new string[count3];
		string* docopd1 = new string[count3];
		string* roomopd1 = new string[count3];
		/*bool condition = false;*/
		filing.open("opdpatientinfo.txt", ios::in);
		if (filing)
		{
			while (!filing.eof())
			{
				for (int k = 0; k < count3; k++)
				{
					filing >> nameopd1[k];
					filing >> idopd1[k];
					filing >> ageopd1[k];
					filing >> genderopd1[k];
					filing >> disopd1[k];
					filing >> docopd1[k];
					filing >> roomopd1[k];
				}
			}
			for (int k = 0; k < count3 - 1; k++)
			{
				cout << "\n\nRECORD OF PAIENT NO " << k + 1 << ":" << endl << endl;
				cout << "NAME:" << nameopd1[k]; cout << endl << endl;
				cout << "PATIENT ID" << idopd1[k]; cout << endl << endl;
				cout << "AGE:" << ageopd1[k]; cout << endl << endl;
				cout << "GENDER:" << genderopd1[k]; cout << endl << endl;
				cout << "DISEASE NAME:" << disopd1[k]; cout << endl << endl;
				cout << "DOCTOR NAME:" << docopd1[k]; cout << endl << endl;
				cout << "ROOM NO:" << roomopd1[k]; cout << endl << endl;
			}
		}
		else
		{
			cout << "\n\nNO RECORD FOUND\n\n";
		}

		if (count3 == 1)
		{
			cout << "\nNO Record Found\n";
		}
		delete[]nameopd1;
		delete[]idopd1;
		delete[]ageopd1;
		delete[]genderopd1;
		delete[]disopd1;
		delete[]docopd1;
		delete[]roomopd1;

	}break;
	case 2:
	{
		int count5 = 0;
		string reading3;
		fstream filing4;
		filing4.open("emgpatientinfo.txt", ios::in);
		if (filing4)
		{
			while (!filing4.eof())
			{
				getline(filing4, reading3);
				count5++;
			}
		}
		else
		{
			cout << "\n\nNO RECORD FOUND\n\n";
		}
		filing4.close();
		string* nameem1 = new string[count5];
		string* idem1 = new string[count5];
		string* ageem1 = new string[count5];
		string* genderem1 = new string[count5];
		string* disem1 = new string[count5];
		string* docem1 = new string[count5];
		string* roomem1 = new string[count5];
		filing4.open("emgpatientinfo.txt", ios::in);
		if (filing4)
		{
			while (!filing4.eof())
			{
				for (int k = 0; k < count5; k++)
				{
					filing4 >> nameem1[k];
					filing4 >> idem1[k];
					filing4 >> ageem1[k];
					filing4 >> genderem1[k];
					filing4 >> disem1[k];
					filing4 >> docem1[k];
					filing4 >> roomem1[k];
				}
			}
			for (int k = 0; k < count5 - 1; k++)
			{
				cout << "\n\nRECORD OF PAIENT NO " << k + 1 << ":" << endl << endl;
				cout << "NAME:" << nameem1[k]; cout << endl << endl;
				cout << "PATIENT ID" << idem1[k]; cout << endl << endl;
				cout << "AGE:" << ageem1[k]; cout << endl << endl;
				cout << "GENDER:" << genderem1[k]; cout << endl << endl;
				cout << "DISEASE NAME:" << disem1[k]; cout << endl << endl;
				cout << "DOCTORS NAME:" << docem1[k]; cout << endl << endl;
				cout << "ROOM NO:" << roomem1[k]; cout << endl << endl;
			}
		}
		else
		{
			cout << "\n\nNO RECORD FOUND\n\n";
		}
		if (count5 == 1)
		{
			cout << "\nNO Record Found\n";
		}
		delete[]nameem1;
		delete[]idem1;
		delete[]ageem1;
		delete[]genderem1;
		delete[]disem1;
		delete[]docem1;
		delete[]roomem1;

	}break;
	case 3:
	{
		int dislist;
		cout << "\n\nPress 1. LIST OF DICHARGE OF OPD PATIENTS\n\n";
		cout << "\n\nPRESS 2. LIST OF DISCHARG OF EMERGENCY PATIENTS\n\n";
		cout << ">>>"; cin >> dislist;
		switch (dislist)
		{
		case 1:
		{
			int count0 = 0;
			string reading0;
			fstream filing0;
			filing0.open("dischargeuser.txt", ios::in);
			if (filing0)
			{
				while (!filing0.eof())
				{
					getline(filing0, reading0);
					count0++;
				}
			}
			else
			{
				cout << "\n\nNO RECORD FOUND\n\n";
			}
			filing0.close();
			string* nameopd2 = new string[count0];
			string* idopd2 = new string[count0];
			string* ageopd2 = new string[count0];
			string* genderopd2 = new string[count0];
			string* disopd2 = new string[count0];
			string* docopd2 = new string[count0];
			string* roomopd2 = new string[count0];
			filing0.open("dischargeuser.txt", ios::in);

			if (filing0)
			{
				while (!filing0.eof())
				{
					for (int k = 0; k < count0; k++)
					{
						filing0 >> nameopd2[k];
						filing0 >> idopd2[k];
						filing0 >> ageopd2[k];
						filing0 >> genderopd2[k];
						filing0 >> disopd2[k];
						filing0 >> docopd2[k];
						filing0 >> roomopd2[k];
					}
				}
				for (int k = 0; k < count0 - 1; k++)
				{
					cout << "\n\nRECORD OF PAIENT NO " << k + 1 << ":" << endl << endl;
					cout << "NAME:" << nameopd2[k]; cout << endl << endl;
					cout << "PATIENT ID" << idopd2[k]; cout << endl << endl;
					cout << "AGE:" << ageopd2[k]; cout << endl << endl;
					cout << "GENDER:" << genderopd2[k]; cout << endl << endl;
					cout << "DISEASE NAME:" << disopd2[k]; cout << endl << endl;
					cout << "DOCTORS NAME:" << docopd2[k]; cout << endl << endl;
					cout << "ROOM NO:" << roomopd2[k]; cout << endl << endl;
				}
			}
			else
			{
				cout << "\n\nNO RECORD FOUND\n\n";
			}
			if (count0 == 1)
			{
				cout << "\nNO Record Found\n";
            }

			delete[]nameopd2;
			delete[]idopd2;
			delete[]ageopd2;
			delete[]genderopd2;
			delete[]disopd2;
			delete[]docopd2;
			delete[]roomopd2;
		}
		break;
		case 2:
		{
			int count01 = 0;
			string reading01;
			fstream filing01;
			filing01.open("dischargeuseremg.txt", ios::in);
			if (filing01)
			{
				while (!filing01.eof())
				{
					getline(filing01, reading01);
					count01++;
				}
			}
			else
			{
				cout << "\n\nNO RECORD FOUND\n\n";
			}
			filing01.close();
			string* nameemg2 = new string[count01];
			string* idemg2 = new string[count01];
			string* ageemg2 = new string[count01];
			string* genderemg2 = new string[count01];
			string* disemg2 = new string[count01];
			string* docemg2 = new string[count01];
			string* roomemg2 = new string[count01];

			filing01.open("dischargeuseremg.txt", ios::in);

			if (filing01)
			{
				while (!filing01.eof())
				{
					for (int k = 0; k < count01; k++)
					{
						filing01 >> nameemg2[k];
						filing01 >> idemg2[k];
						filing01 >> ageemg2[k];
						filing01 >> genderemg2[k];
						filing01 >> disemg2[k];
						filing01 >> docemg2[k];
						filing01 >> roomemg2[k];
					}
				}
				for (int k = 0; k < count01 - 1; k++)
				{
					cout << "\n\nRECORD OF PAIENT NO " << k + 1 << ":" << endl << endl;
					cout << "NAME:" << nameemg2[k]; cout << endl << endl;
					cout << "PATIENT ID" << idemg2[k]; cout << endl << endl;
					cout << "AGE:" << ageemg2[k]; cout << endl << endl;
					cout << "GENDER:" << genderemg2[k]; cout << endl << endl;
					cout << "DISEASE NAME:" << disemg2[k]; cout << endl << endl;
					cout << "DOCTORS NAME:" << docemg2[k]; cout << endl << endl;
					cout << "ROOM NO:" << roomemg2[k]; cout << endl << endl;
				}
			}
			else
			{
				cout << "\n\nNO RECORD FOUND\n\n";
			}
			if (count01 == 1)
			{
				cout << "\nNO Record Found\n";
			}

			delete[]nameemg2;
			delete[]idemg2;
			delete[]ageemg2;
			delete[]genderemg2;
			delete[]disemg2;
			delete[]docemg2;
			delete[]roomemg2;
		}break;
		default:
		{

			cout << "Inavlid INput" << endl;
			cout << "Press 0 for main menu:";
			cin >> variable1;
			while (variable1 < 0 || variable1>0)
			{
				cout << "Press 0 for main menu";
				cin >> variable1;
			}
		}
		}
	}
	break;
	default:
	{

		cout << "Inavlid INput" << endl;
		cout << "Press 0 for main menu:";
		cin >> variable1;
		while (variable1 < 0 || variable1>0)
		{
			cout << "Press 0 for main menu";
			cin >> variable1;
		}
	}
	}
}


void dischargepatient()
{
	int variable1;
	string nameop1, idop1;
	int disc;
	bool condition1 = false;
	bool condition2 = false;
	cout << "\n\nPRESS 1. DISCHARGE THE OPD PATEINT\n\n";
	cout << "\nPRESS 2. DISCHARGE THE EMERGENCY PATIENT\n\n";
	cout << ">>>"; cin >> disc;

	switch (disc)
	{
	case 1:
	{
		int count3 = 0;
		string reading;
		fstream filing, filingdischarge;
		filing.open("opdpatientinfo.txt", ios::in);
		filingdischarge.open("dischargeuser.txt", ios::out | ios::app);
		if (filing)
		{
			while (!filing.eof())
			{
				getline(filing, reading);
				count3++;
			}
		}
		filing.close();
		/*cout << "\n\nLINES IN FILE:" << count3 << endl << endl;*/
		string* nameopd1 = new string[count3];
		string* idopd1 = new string[count3];
		string* ageopd1 = new string[count3];
		string* genderopd1 = new string[count3];
		string* disopd1 = new string[count3];
		string* docopd1 = new string[count3];
		string* roomopd1 = new string[count3];


		filing.open("opdpatientinfo.txt", ios::in);
		if (filing)
		{
			while (!filing.eof())
			{
				for (int k = 0; k < count3; k++)
				{
					filing >> nameopd1[k];
					filing >> idopd1[k];
					filing >> ageopd1[k];
					filing >> genderopd1[k];
					filing >> disopd1[k];
					filing >> docopd1[k];
					filing >> roomopd1[k];
				}
			}
			filing.close();
			/*cout << endl << nameopd1[0] << endl;*/
			cout << "\nPlease ENTER NAME OF PATIENT TO DISCHARGE:\n";
			cout << ">>>"; cin >> nameop1;
			cout << "\nPLEASE ENTER ID OF THE PaTiENT TO DISCHARGE:\n";
			cout << ">>>"; cin >> idop1;
			filing.open("opdpatientinfo.txt", ios::out);
			for (int k = 0; k < count3; k++)
			{
				if (nameopd1[k] == nameop1 && idopd1[k] == idop1)
				{
					condition1 = true;
					filingdischarge << nameopd1[k] << " ";
					filingdischarge << idopd1[k] << " ";
					filingdischarge << ageopd1[k] << " ";
					filingdischarge << genderopd1[k] << " ";
					filingdischarge << disopd1[k] << " ";
					filingdischarge << docopd1[k] << " ";
					filingdischarge << roomopd1[k] << " ";
					if (k != count3 - 1)
					{
						filingdischarge << endl;
					}
					nameopd1[k] = -99;
					idopd1[k] = -99;
					ageopd1[k] = -99;
					genderopd1[k] = -99;
					disopd1[k] = -99;
					docopd1[k] = -99;
					roomopd1[k] = -99;


					cout << "\n\nPATIENT DISCHARGED SUCCESFULLY\n\n";
				}
				/*if (nameopd1[k] != nameop1 && idopd1[k] != idop1)*/

				else
				{
					if (nameopd1[k] != "-99")
					{
						filing << nameopd1[k] << " ";
						filing << idopd1[k] << " ";
						filing << ageopd1[k] << " ";
						filing << genderopd1[k] << " ";
						filing << disopd1[k] << " ";
						filing << docopd1[k] << " ";
						filing << roomopd1[k] << " ";
						if (k != count3 - 1)
						{
							filing << endl;
						}
					}
				}
			}
			if (condition1 == false)
			{
				cout << "\\n\n\nRESPECTIVE PATIENT RECORD NOT FOUND\n\n\n";
			}

		}
		else
		{
			cout << "\n\nFILE NOT FOUND\n\n";
		}

		delete[]nameopd1;
		delete[]idopd1;
		delete[]ageopd1;
		delete[]genderopd1;
		delete[]disopd1;
		delete[]docopd1;
		delete[]roomopd1;
	}
	break;
	case 2:
	{
		int count6 = 0;
		string reading6;
		fstream filing6, filingdischarge6;
		filing6.open("emgpatientinfo.txt", ios::in);
		filingdischarge6.open("dischargeuseremg.txt", ios::out | ios::app);
		if (filing6)
		{
			while (!filing6.eof())
			{
				getline(filing6, reading6);
				count6++;
			}
		}
		filing6.close();

		string* nameemg1 = new string[count6];
		string* idemg1 = new string[count6];
		string* ageemg1 = new string[count6];
		string* genderemg1 = new string[count6];
		string* disemg1 = new string[count6];
		string* docemg1 = new string[count6];
		string* roomemg1 = new string[count6];

		filing6.open("emgpatientinfo.txt", ios::in);
		if (filing6)
		{
			while (!filing6.eof())
			{
				for (int k = 0; k < count6; k++)
				{
					filing6 >> nameemg1[k];
					filing6 >> idemg1[k];
					filing6 >> ageemg1[k];
					filing6 >> genderemg1[k];
					filing6 >> disemg1[k];
					filing6 >> docemg1[k];
					filing6 >> roomemg1[k];
				}
			}
			filing6.close();
			string nameem1, idem1;
			cout << "\nPlease ENTER NAME OF PATIENT TO DISCHARGE:\n";
			cout << ">>>"; cin >> nameem1;
			cout << "\nPLEASE ENTER ID OF THE PaTiENT TO DISCHARGE:\n";
			cout << ">>>"; cin >> idem1;

			filing6.open("emgpatientinfo.txt", ios::out);


			for (int k = 0; k < count6; k++)
			{
				if (nameemg1[k] == nameem1 && idemg1[k] == idem1)
				{
					condition2 = true;
					filingdischarge6 << nameemg1[k] << " ";
					filingdischarge6 << idemg1[k] << " ";
					filingdischarge6 << ageemg1[k] << " ";
					filingdischarge6 << genderemg1[k] << " ";
					filingdischarge6 << disemg1[k] << " ";
					filingdischarge6 << docemg1[k] << " ";
					filingdischarge6 << roomemg1[k] << " ";
					if (k != count6 - 1)
					{
						filingdischarge6 << endl;
					}
					nameemg1[k] = -99;
					idemg1[k] = -99;
					ageemg1[k] = -99;
					genderemg1[k] = -99;
					disemg1[k] = -99;
					docemg1[k] = -99;
					roomemg1[k] = -99;


					cout << "\n\nPATIENT DISCHARGED SUCCESFULLY\n\n";
				}

				else
				{
					if (nameemg1[k] != "-99")
					{
						filing6 << nameemg1[k] << " ";
						filing6 << idemg1[k] << " ";
						filing6 << ageemg1[k] << " ";
						filing6 << genderemg1[k] << " ";
						filing6 << disemg1[k] << " ";
						filing6 << roomemg1[k] << " ";
						if (k != count6 - 1)
						{
							filing6 << endl;
						}
					}
				}




			}
			if (condition2 == false)
			{
				cout << "\\n\n\nRESPECTIVE PATIENT RECORD NOT FOUND\n\n\n";
			}


		}
		else
		{
			cout << "\n\nFILE NOT FOUND\n\n";
		}

		delete[]nameemg1;
		delete[]idemg1;
		delete[]ageemg1;
		delete[]genderemg1;
		delete[]disemg1;
		delete[]docemg1;
		delete[]roomemg1;



	}break;
	default:
	{

		cout << "Inavlid INput" << endl;
		cout << "Press 0 for main menu:";
		cin >> variable1;
		while (variable1 < 0 || variable1>0)
		{
			cout << "Press 0 for main menu";
			cin >> variable1;
		}
	}
	}
}
/*filing.close();*/



void docadd()
{
	int variable1;
	string docnam;
	string docspc;
	string docage;
	fstream fili,fili1;
	fili.open("docprofilerecord.txt", ios::out|ios::app);
	fili1.open("docprofile.txt", ios::out | ios::app);
	char docgender;
	/*do
	{
		variable1 = 1;
		while (variable1 != 0)
		{*/
			cout << "\n\n    THIS IS DOCTOR PROFILE MEUN\n\n";
			cout << "\n\n------------------------------------------\n\n";
			cout << "\n\nPLEASE ENTER DOCTORS NAME:\n\n";
			cin >> docnam;
			cout << "\n\nPLEASE ENTER DOCTOR SPECIALIZATION\n\n";
			cin >> docspc;
			cout << "\n\n PLEASE ENTER DOCTOR AGE:";
			cin >> docage;
			cout << "\n\nPLEASE ENTER DOCTOR GENDER: (f/m)\n\n";
			cin >> docgender;
			while (docgender != 'm' && docgender != 'M' && docgender != 'F' && docgender != 'f')
			{
				cout << "PLease enter correct gender again:"; cin >> docgender;
			}
			cout << endl; cout << endl;
			fili << docnam << " " << docspc << " " << docage << " " << docgender << endl;
			fili1 << docnam << endl;

			cout << "Press 0 for main menu && 1 for TO ADD:";
			cin >> variable1;
			while (variable1 < 0 || variable1>1)
			{
				cout << "Now Press 0 for main menu:";
				cin >> variable1;
			}
			fili.close();
			fili1.close();
		/*}
	} while (variable1 == 0);*/

}

void doclist()
{
	int countdoc = 0;
	string readingdoc;
	fstream filingdoc;
	filingdoc.open("docprofilerecord.txt", ios::in);
	if (filingdoc)
	{
		while (!filingdoc.eof())
		{
			getline(filingdoc, readingdoc);
			countdoc++;
		}
	}
	else
	{
		cout << "\n\nNO RECORD FOUND\n\n";
	}

	filingdoc.close();
	string* namedoc1 = new string[countdoc];
	string* spsdoc1 = new string[countdoc];
	string* agedoc1 = new string[countdoc];
	string* genderdoc1 = new string[countdoc];

	filingdoc.open("docprofilerecord.txt", ios::in);
	if (filingdoc)
	{
		while (!filingdoc.eof())
		{
			for (int k = 0; k < countdoc; k++)
			{
				filingdoc >> namedoc1[k];
				filingdoc >> spsdoc1[k];
				filingdoc >> agedoc1[k];
				filingdoc >> genderdoc1[k];
			}
		}
		cout << "\n\n                          HOSPITAL DOCTOR LIST\n\n";
		cout << "--------------------------------------------------------------------------------------------------\n";
		/*cout << "SR#\tNAME\tSPECILIAZATION\tAGE\tGENDER\n";*/
		for (int k = 0; k < countdoc - 1; k++)
		{
			/*cout<<k+1<<"\t" << namedoc1[k] << "\t" << spsdoc1[k] << "\t" << agedoc1[k] << "\t" << genderdoc1[k] << endl;*/
			cout << "DOCTOR NO " << k + 1<<":"; cout << endl<<endl;
			cout << "NAME:" << namedoc1[k]; cout << endl << endl;
			cout << "DOCTOR SPECILAIZATION" << spsdoc1[k]; cout << endl << endl;
			cout << "AGE:" << agedoc1[k]; cout << endl << endl;
			cout << "GENDER:" << genderdoc1[k]; cout << endl << endl;
		}

		delete[]namedoc1;
		delete[]spsdoc1;
		delete[]agedoc1;
		delete[]genderdoc1;

	}
	else
	{
		cout << "\n\nNO FILE FOUND\n\n";
	}

}



void newacc()
{
	string name;
	string password;
	fstream file;
	fstream file3;
	
	/*bool flagoi = true;*/
	file.open("Users.txt", std::ios::out | std::ios::app);

	cout << "\n\nNew Account Sign Up\n\n";
	cout << "\nEnter USername:";
	cout << "\n>>"; cin >> name;
	file3.open("usernames.txt", ios::in);
	if (file3)
	{
		int res = namecheck(name);
		while (res == 1)
		{
			cout << "\nTHIS USER NAME IS ALREADY OCCUPIED\n";
			cout << "\nENTER DIFFERENT USERNAME\n";
			cin >> name;
		    res = namecheck(name);
		}
		    cout << "\nTHE NAME YOU ENTERED IS:" << name;
			cout << "\nENter Password";
			cout << "\n>>"; cin >> password;
			file3.open("usernames.txt", ios::out | ios::app);
			file << name << endl;
			file << password << endl;
			file3 << name << endl;
			file3.close();

	}
	else
	{
		cout << "\nENter Password";
		cout << "\n>>"; cin >> password;
		file3.open("usernames.txt", ios::out | ios::app);
		file << name << endl;
		file << password << endl;
		file3 << name << endl;

		file3.close();
		
	}

	file.close();


	
}


int namecheck(string name)
{
	int flago=0;
	string read;
	fstream file3;
	file3.open("usernames.txt", ios::in);
	while (!file3.eof())
	{
		file3 >> read;
		if (name == read)
		{
			flago = 1;
			break;
		}
		else
		{
			flago = 0;
		}
	}
	return flago;
}


int roomopdcheck(string roomO)
{
	int check=0;
	string read;
	fstream fileroom;
	fileroom.open("roomsopd.txt", ios::in);
	while (!fileroom.eof())
	{
		fileroom >> read;
		if (roomO == read)
		{
			check = 1;
			break;
		}
		else
		{
			check = 0;
		}
	}
	return check;
}


int roomemgcheck(string roomE)
{
	int check1 = 0;
	string read1;
	fstream fileroom1;
	fileroom1.open("roomsemg.txt", ios::in);
	while (!fileroom1.eof())
	{
		fileroom1 >> read1;
		if (roomE == read1)
		{
			check1 = 1;
			break;
		}
		else
		{
			check1 = 0;
		}
	}
	return check1;
}

int main()
{
	/*time_t tt;

	struct tm* ti;
	time(&tt);
	ti = localtime_s(tt);

	cout << "\n\n\nCURRENT DATA AND TIME IS:";
	cout << asctime_s(ti);
	cout << endl << endl << endl;*/
	welcome();

	login();



}
