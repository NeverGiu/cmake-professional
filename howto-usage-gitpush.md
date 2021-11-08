<!-- How to using git to push the local branch(files) to github remotes ? -->

Step 1: Initial git-work:
<!-- make a new directory and enter it, initialing git creation -->
<!-- (if '.git' directory is not exist), -->
	mkdir -p xxx-project
	cd xxx-project
	git init
<!-- or clone the remotes codes repository 'xxx-project' to local -->
	git clone git@github.com:user.name/xxx-project.git
	cd xxx-project

Step 2: Create tracking for items in directory 'xxx-project':
<!-- for selected files -->
	git add xxx.*
	git add *.xxx
	...
<!-- or directory -->
	git add xxx

Step 3: Commit the items that already been added in cache location to local repository:
<!-- you can add some commit infomations here -->
	git commit -m "Some commit infomations here."

Step 4: Check current branch:
<!-- ckeck local branch -->
	git branch 
<!-- check remote branch -->
	git branch -a
<!-- creat a new local branch(if we need and it is not exist) -->
	git checkout -b arcticle_1
<!-- switch to the desired local branch(if we need and it is exist) -->
	git checkout arcticle_1
<!-- delete local branch(if we need and it is exist) -->
	git branch -d arcticle_new
	
Step 5: Linking remotes codes repository with local codes repository:
<!-- if they are already been linked, skip this step -->
	git remote add origin git@github.com:user.name/xxx-project.git

Step 6: Push the current branch(items) to the remotes repository's branch:
<!-- this sub-step must be in head if we need(obtain remote repository items -->
<!-- and merge with local repository items synchronously) -->
	git pull --rebase origin arcticle_1
<!-- then push the current branch(items) 'arcticle_1' to the remotes repository's  -->
<!-- corresponding branch 'arcticle_1' and coverage items -->
	git push -u origin arcticle_1
<!-- if we want to push a new branch(items) 'arcticle_new' that the remotes repository -->
<!-- dose not contain it, we can usage codes as below -->
<!-- (local branch name is the same as remotes branch name) -->
	git push origin arcticle_new:arcticle_new
<!-- if we want to delete an exist remotes branch, we can do this -->
	git push origin --delete arcticle_new

Done...
