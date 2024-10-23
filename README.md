# Breakout

W Kavanagh. June Summer 2024

## controls

A/D to move the paddle right and left.
P to pause.

## Powerups

big/small paddle (blue)
fast/slow ball (fancy yellow)
fire ball (green)

# Tasklist

## Suggested fixes

* Fix the compiler issues in the code

## Suggested tasks

* Implement mouse input for pad
* Improved VFX (ball trail, paddle hit response, brick particle destruction)
* Better UI (progress bar rather than timer for countdown).
* GameLoop
* Better ball physics (Box2D)
* Leaderboards
* More ball types (e.g., multiball, sticky ball [where you shoot the ball from the paddle every time], tiny ball, big ball, brick-tracking ball)
* Sounds with increasing tone between bounces.
* Implement commentary with calls to an LLM such as LLama

# Time Details and Changelist
<Add information to this section about the time you've taken for this task along with a professional changelist.>

---
Time when I Started working on the project: 9:21 PM
Commit 3b15aaaf3b14ef84e4ab887c2dca44cf0ddbd427 - Fixed Include errors made from Rider IDE

Time when I finished and pushed my last commit: 1:12AM
Commit 6701ba1b78e05ed39ffa647f2396244bb3e9b045 - Made Power Ups have a vanishing effect when close to bottom

Time Taken: 03:51
---

Total Time: 03:10 (05:10*)

> Features:
    Commits: 897ad121579ad324aaa761b4d5f9c98bc5cccb77
    Total Time: 01:30
    Changes:
        - Implemented a Smooth Screen Shake Effect when ball is lost

> Tweaks:
    Commits: 6701ba1b78e05ed39ffa647f2396244bb3e9b045, 1692e75d7f39b4a9f65f6293faad215273525c23,268fa2cd6162bf6b9875657e2fd5a528b7116ed2
    Total Time: 00:30
    Changes:
        - Added a Vanishing Effect when power ups are reaching bottom of the screen (making them transparent before touching the bottom)
        - Redone the logic on the Pause System, now you can Pause and Unpause instantly
        - Added a paramater so developer can change the randomization of spawing power ups

> Bugs: 
    Commits: b984aec2f65a2889bb99c1ca6b0b81037aa962ea, 87e8eb199c90fdeb77eb5a428977c453079a2a50
    Description:
    Total Time: 00:40
    Changes:
        - Made sure that the Pause/Game Over/Level Complete messages always appear on the center of the screen
        - Fixed Circular Dependecy that was not leeting game run at the beginning

> Clean Up:
    Commits: cc876c046191169a9ab599d45c27cd21e5e54bac, 2fbacd29099f0c67312af34a7b33a0d886e9716e, 31f1642c206c94f3377b695e03ef3db18c51ced5, 5a8bff883148bfb7b1f93ca3909ee5fb1e8cb591, 660361339b7ed0c04237a24a0aa830fae3c1eb43, 6b5fd18895e045be2f89c648e0070e89331040fc, e6db18ac5f427aadbef742d18d7db02e9c21f462, 3b15aaaf3b14ef84e4ab887c2dca44cf0ddbd427, 2e12e1ddf87c10bf9ecc4585091768db796bcc83
    Description:
    Total Time: 00:30 (2:00*)
    Changes:
        - Code Clean Up
        - Code and Folder Organization

*I say 2 hours, that I dont really count due to my IDE changing the include settings for each single file, making me have to chase and fix them
    

