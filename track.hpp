/*
  track.hpp
  Author: M00832048
  Created: 10/4/2023
  Updated: 21/4/2023
*/

/*
  Including statements
*/
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "track.h"

/*
  Variable declaration
*/
int number;
int key;
std::string temp_var;
std::string track_to_remove;
std::string textSample;
std::string textSample2;
std::string file_name;
std::string track_name;
std::string track_artist;
std::string track_duration;
bool condition = true;
bool isEmpty = false;
static const int array_size = 5000;
Track table[array_size];
Track table_compare[array_size];

/*
  Hash function.
  Used to calculate a hash key to store values in a table.
*/
int hashFunction(int key)
{
  return key % array_size;
}

/*
  load_file function.
  Used to load contents of the file into a table of class Track
*/
int load_file(std::string file_name)
{
  if (!(table[0].getName().empty()))
  {
    std::cout << "\nFILE HAS ALREADY BEEN LOADED.\n";
    return 1;
  }

  std::ifstream FileReader(file_name); 
  std::string word;

  for(int i = 0; i < array_size; i++)
  {
    if(!FileReader.eof()){
        key = hashFunction(i);
        std::getline(FileReader, textSample);
        int count = 0;
        if (!textSample.empty()) 
        {
          for (size_t z = 0; z < textSample.length(); z++) 
          {
            char c = textSample[z];
            if (c != '\t')
            {
              word += c;
            } else {
              count += 1;
              if (count == 1)
              {
                track_name = word;
              } 
              else if (count == 2)
              {
                track_artist = word;
              }
              word.clear();
              continue;
            }
            if (z == textSample.length() - 1)
            {
              track_duration = word;
              word.clear();
              break;
            }
          }
        }
        else
        {
          std::cout << "NO FILE LOADED. FILE DOES NOT EXIST" << std::endl;
          return 1;
        }

        for (int j = key; j < array_size; j++)
        {
          if (table[j].getName().empty())
          {
            table[j].setName(track_name);
            table[j].setArtist(track_artist);
            table[j].setDuration(track_duration);
            break;
          }
        }
    } 
    else 
    {
      break;
    }    
  }
  std::cout << "FILE HAS BEEN LOADED SUCCESSFULLY" << std::endl;
  return 0;
}

/*
  save_file function.
  Used to save the changes made to the table onto the file.
*/
void save_file()
{
  std::ofstream FileWriter;
  FileWriter.open(file_name);

  for (int x = 0; x < array_size; x++)
  {
    if (!(table[x].getName().empty()))
    {
      if (x > 0)
      {
        FileWriter << "\n" << table[x].getName() << "\t" << table[x].getArtist()
                    << "\t" << table[x].getDuration();
      } 
      else 
      {
        FileWriter << table[x].getName() << "\t" << table[x].getArtist()
                    << "\t" << table[x].getDuration();
      }
    } 
    else 
    {
      break;
    }
  }

  FileWriter.close();
  std::cout << "\nFILE HAS BEEN SUCCESSFULLY SAVED\n" << std::endl;
}

/*
  search_track function.
  Used to search within the table for  track that is similar to the input.
*/
void search_track()
{
  int count2 = 0;
  std::cout << "\nENTER TRACK/ARTIST TO SEARCH: ";


  // Clear input buffer
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, temp_var);

  for (int y = 0; y < array_size; y++)
  {
    if (!(table[y].getName().empty()))
    {
      size_t item_find = table[y].getName().find(temp_var);
      if (item_find != std::string::npos && 
          table[y].getName().substr(item_find, temp_var.length())
          == temp_var) 
      {
        std::cout << "Name: " << table[y].getName() << std::endl;
        std::cout << "Artist: " << table[y].getArtist() << std::endl;
        std::cout << "Duration: " << table[y].getDuration() << std::endl;
        std::cout << "\n";
        count2 += 1;
      }

      item_find = table[y].getArtist().find(temp_var);
      if (item_find != std::string::npos && 
          table[y].getArtist().substr(item_find, temp_var.length()) 
          == temp_var) 
      {
        std::cout << "Name: " << table[y].getName() << std::endl;
        std::cout << "Artist: " << table[y].getArtist() << std::endl;
        std::cout << "Duration: " << table[y].getDuration() << std::endl;
        std::cout << "\n";
        count2 += 1;
        continue;
      }
    } 
    else 
    {
      break;
    }
  }

  if (count2 == 0)
  {
    std::cout << "No track found" << std::endl;
  }
}

/*
  remove_track function.
  Used to remove a track based on a search result.
*/
void remove_track()
{
  int count = 0;
  std::cout << "\nENTER TRACK TO REMOVE: ";

  // Clear input buffer
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, track_to_remove);

  for (int m = 0; m < array_size; m++)
  {
    if (!(table[m].getName().empty()))
    {
      size_t item_find_remove = table[m].getName().find(track_to_remove);
      if (item_find_remove != std::string::npos && 
          table[m].getName().substr(item_find_remove, 
          track_to_remove.length()) 
          == track_to_remove) 
      {
        for (int n = m; n < array_size - 1; n++)
        {
          table[n] = table[n + 1];
        }
        std::cout << "REMOVED SUCCESSFULLY" << std::endl;
        count += 1;
        break;
      }

      item_find_remove = table[m].getArtist().find(track_to_remove);

      if (item_find_remove != std::string::npos && 
          table[m].getArtist().substr(item_find_remove, 
          track_to_remove.length())
          == track_to_remove) 
      {
        for (int n = m; n < array_size - 1; n++){
          table[n] = table[n + 1];
        }
        std::cout << "REMOVED SUCCESSFULLY" << std::endl;
        count += 1;
        break;
      }
    } 
    else 
    {
      break;
    }
  }

  if (count == 0)
  {
    std::cout << "No track found" << std::endl;
  }
}

/*
  continue_prompt function.
  Used to induce a required input by the user in order to continue using
  the code.
*/
void continue_prompt()
{
  do 
  {
    std::cin.ignore();
    std::cout << "\nPRESS ENTER TO CONTINUE";
  } while (std::cin.get() != '\n');
}

/*
  exit_program function.
  Used to terminate the code without errors or interrupts.
*/
void exit_program()
{
  std::ifstream FileCompare(file_name);
  std::string word_compare;

  for(int k = 0; k < array_size; k++)
  {
    if(!FileCompare.eof())
    {
        key = hashFunction(k);
        std::getline(FileCompare, textSample2);
        int count = 0;
        if (!textSample2.empty()) 
        {
          for (size_t z = 0; z < textSample2.length(); z++) 
          {
            char c = textSample2[z];
            if (c != '\t')
            {
              word_compare += c;
            } 
            else 
            {
              count += 1;
              if (count == 1)
              {
                track_name = word_compare;
              } 
              else if (count == 2)
              {
                track_artist = word_compare;
              }
              word_compare.clear();
              continue;
            }
            if (z == textSample2.length() - 1)
            {
              track_duration = word_compare;
              word_compare.clear();
              break;
            }
          }
        }

        for (int l = key; l < array_size; l++)
        {
          if (table_compare[l].getName().empty())
          {
            table_compare[l].setName(track_name);
            table_compare[l].setArtist(track_artist);
            table_compare[l].setDuration(track_duration);
            break;
          }
        } 
    } 
    else 
    {
      break;
    } 
  }

  for (int w = 0; w < array_size; w++)
  {
    if (table_compare[w].getName().empty() != table[w].getName().empty())
    {
      save_file();
    }
  }

  condition = false;
}

/*
  menu function.
  Used to display all possible inputs for the user to be able to use the 
  program.
*/
void menu(){
  while (condition == true)
  {
    std::cout << "\n\n******CHOOSE FROM OPTIONS AVAILABLE:******";
    std::cout << "\n1: LOAD TRACKS FROM FILE";
    std::cout << "\n2: SAVE TRACKS TO FILE";
    std::cout << "\n3: SEARCH";
    std::cout << "\n4: REMOVE TRACK";
    std::cout << "\n5: EXIT";

    std::cout << "\n\nENTER THE CHOSEN OPTION'S NUMBER: ";
    std::cin >> number;

    if (number < 1 || number > 5)
    {
      std::cout << "\n\n";
      menu();
    } 
    else 
    {
      switch(number)
      {
        case 1:
          {
            std::cout << "NAME OF FILE: ";
            std::cin >> file_name;
            load_file(file_name);
            continue_prompt();
            break;
          }
        case 2:
          {
            save_file();
            continue_prompt();
            break;
          }
        case 3:
          {
            search_track();
            continue_prompt();
            break;
          }
        case 4:
          {
            remove_track();
            continue_prompt();
            break;
          }
        case 5:
          {
            exit_program();
            break;
          }
      }
    }
  }
  return;
}
