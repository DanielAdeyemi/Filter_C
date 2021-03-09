 if (count == 0) // first file we found
            {
                sprintf(filename, "%03i.jpg", count); // create name of the file
                jpg = fopen(filename, "w"); //open file for writing
                fwrite(buffer, 512, 1, jpg); // write data from buffer to the file jpg
                count++; // increase count for files
                fclose(jpg);
            }
            else // not the first file == new file