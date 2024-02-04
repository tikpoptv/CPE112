// คุณได้รับมอบหมายให้สร้างโปรแกรมที่จำลอง Doubly Linked List โปรแกรมควรประมวลผลคำสั่งและข้อมูลในลำดับต่อไปนี้เพื่อสร้าง、ดำเนินการ และแสดงผล Doubly Linked List

// คำสั่งที่ต้องรองรับคือ:

// ADD x: สร้างโหนดที่มีค่า x และเพิ่มไปยังโหนดที่สร้างล่าสุด หากยังไม่มีโหนดที่สร้างไว้ก่อนหน้านี้ คำสั่งนี้จะสร้างโหนดแรก
// DEL x: ลบโหนดแรกที่มีค่าเท่ากับ x หากไม่พบโหนดที่มีค่าตรงกัน คำสั่งนี้จะถูกละเว้น
// SCH x: ค้นหาโหนดที่ต่อไปของโหนดแรกที่มีค่า x ซึ่งหมายถึงการค้นหาโหนดที่อยู่ก่อนและหลังของโหนดที่กำหนด หากไม่มีโหนดที่มีค่าที่ระบุ ให้พิมพ์ 'none'
// END: สัญญาณที่บอกถึงการสิ้นสุดการสร้างรายการ
// หลังจากประมวลผลคำสั่ง โปรแกรมควรพิมพ์ผลลัพธ์ที่สุดท้ายของ Doubly Linked List ในลำดับทั้งสิ้นและถอยหลัง

// ข้อมูลนำเข้า:

// ข้อมูลนำเข้าประกอบด้วยบรรทัดหลาย ๆ บรรทัด แต่ละบรรทัดมีคำสั่งและค่าข้อมูลที่คั่นด้วยช่องว่าง
// สิ้นสุดส่วนข้อมูลนำเข้าด้วยคำสั่ง 'END'
// ผลลัพธ์:

// เมื่อคำสั่งเป็น 'SCH' โปรแกรมควรพิมพ์ค่าของโหนดที่อยู่ก่อนและหลังโหนดที่ระบุ
// บรรทัดที่สองจากท้ายควรแสดงผลโหนดผลลัพธ์ในลำดับที่ผ่านมา
// บรรทัดสุดท้ายควรแสดงผลโหนดผลลัพธ์ในลำดับที่ถอยหลัง

// You are tasked with implementing a program that simulates a doubly linked list. The program should process a series of commands and data values to create, manipulate, and display the doubly linked list.

// The following commands should be supported:

// ADD x: Create a node with the value x and append it to the last node created. If no nodes have been created yet, this command will create the first node.

// DEL x: Delete the first node with a value equal to x. If no node with the matched value is found, this command is ignored.

// SCH x: Search for the neighbor nodes of the first node with the value x. This involves finding the nodes that come before and after the given node. If there is no node with the specified value, print 'none'.

// END: Signal the termination of creating the list.

// After processing the commands, the program should print the final result of the doubly linked list in both forward and backward orders.

// Input:

// The input consists of multiple lines, each containing a command and data value separated by whitespace.
// End the input section with the command 'END'.
// Output:

// When the command is 'SCH', the program should print the values of the nodes that come before and after the specified node.
// The second-to-last line of output should display the result node in forward order.
// The last line of output should display the result node in backward order.

// สร้างฟังชั่น ADD_x
// สร้างฟังชั่น DEL_x
// สร้างฟังชั่น SCH_x
