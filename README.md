# cautious-babu

* Created an online account sxp63021 on github
* On github, i created cautious-babu repository

* From the vmware linux, i did the following commands to 
  add the files in this repository

  1. git init
  2. git add REAMDE.md (this file was already created)
  3. git commit -m "first commit"
  4. git remote add origin https://github.com/sxp63021/sp-public.git
  5. git push -u origin master

  While doing this, command 4 was wrong, so i had to run following cmd
  4.5. git remote set-url origin https://github.com/sxp63021/sp-public

  Verify if it has changed, using "git remote -v"

* how to change a file and add it to git repository
  1. touch <file>
  2. git status -> see that the file has changed
  3. git add <file>
  4. git commit -> uncomment that file so we know it is changed
  5. git status -> we will see that our branch is ahead of the main branch
  6. git push -u origin master

* How to add an existing directory
  1. git add <dir_name>
  2. git add <dir_name>/*
  3. git commit -a
  4. git push -u origin master




