/*1.	Display TransactionDate, CustomerName, and Item Sold (obtained from the total number of items sold) for every transactions that occured in Quarter 1 of the year 2024. correct*/
SELECT st.TransactionDate, mc.CustomerName, SUM(td.Quantity) AS ItemSold
FROM SalesTransaction st
JOIN MsCustomer mc ON st.CustomerID = mc.CustomerID
JOIN TransactionDetail td ON td.TransactionID = st.TransactionID
WHERE YEAR(st.TransactionDate) = 2024 
AND MONTH(st.TransactionDate) BETWEEN 1 AND 3
GROUP BY TransactionDate, CustomerName; 


/*2.	Display CustomerID, TransactionDate, CustomerName, PaymentType (obtained from PaymentType in uppercase format), TransactionCount (obtained from the total number of sales transactions the customer has ever done) for every transaction with the 'TransferBank' PaymentType and was done in the year 2024. correct */
SELECT st.CustomerID, st.TransactionDate, mc.CustomerName, 
    UPPER(st.PaymentType) AS PaymentType, 
    COUNT(st.TransactionID) AS TransactionCount
FROM SalesTransaction st
JOIN MsCustomer mc ON st.CustomerID = mc.CustomerID
WHERE st.PaymentType = 'Transfer Bank' 
AND YEAR(TransactionDate) = 2024
GROUP BY st.CustomerID, st.TransactionDate, mc.CustomerName, st.PaymentType;

/*3.	Display Date Purchased (obtained from the PurchaseDate in 'Mon dd, yyyy' format), ItemArrived (obtained by adding 1 week to the PurchaseDate in 'Mon dd, yyyy' format), DistributorID, StaffName, Phone Number (obtained by adding (+62) before StaffPhone), Total Item Type (obtained from the total number of different items bought), Total Item Purchased (obtained from the total item's quantity bought) for every purchase transaction where the CategoryID is 'CI005' and StaffGender is 'Female'.*/
SELECT
    CONVERT(VARCHAR, PurchaseDate, 107) AS [Date Purchased],
    CONVERT(VARCHAR, DATEADD(WEEK, 1, PurchaseDate), 107) AS ItemArrived,
    md.DistributorID, StaffName, '+62 ' + StaffPhoneNumber AS [Phone Number],
    COUNT(DISTINCT mi.ItemID) AS [Total Item Type],
    SUM(PD.Quantity) AS [Total Item Purchased]
FROM PurchaseDetail PD
JOIN MsItem mi ON pd.ItemID = mi.ItemID
JOIN MsPurchase mp  ON pd.PurchaseID = mp.PurchaseID
JOIN MsDistributor md ON mp.DistributorID = md.DistributorID
JOIN MsStaff ms ON mp.StaffID = ms.StaffID
WHERE mi.CategoryID = 'CI005' AND ms.StaffGender = 'Female'
GROUP BY md.DistributorID, mp.PurchaseDate, ms.StaffName, ms.StaffPhoneNumber
ORDER BY mp.PurchaseDate;


/*4.	Display Staff First Name (obtained from the first name of the StaffName), Street Name (obtained from StaffAddress), Max Item Price Handled (obtained from the maximum total item's price, calculated by multiplying the item price by quantity), Average Item Price Handled (obtained from the average total item's price, calculated by multiplying the item price by quantity) for every staff who has handled a purchase transaction in Saturday or Sunday and where Max Item Price Handled is greater than 700000.*/
SELECT 
    LEFT(StaffName, CHARINDEX(' ', StaffName + ' ')- 1) AS 'Staff First Name',
    SUBSTRING(StaffAddress, CHARINDEX('Street', StaffAddress), LEN(StaffAddress)) AS 'Street Name',
    MAX(CAST(ItemPrice AS float) * Quantity) AS 'Max Item Price Handles',
    AVG(ItemPrice * Quantity) AS 'Average Item Price Handled'
FROM MsStaff ms 
JOIN MsPurchase mp ON ms.StaffID = mp.StaffID
JOIN PurchaseDetail pd ON mp.PurchaseID = pd.PurchaseID
JOIN MsItem mi  ON pd.ItemID = mi.ItemID
WHERE DATENAME(dw, mp.PurchaseDate) IN ('Saturday', 'Sunday') 
AND (ItemPrice * Quantity) > 700000
GROUP BY StaffName, StaffAddress;

/*5.	Display Item No (obtained from ItemID by replacing ‘IT’ to ‘Item’), Different Items Bought (obtained from the total number of different items bought), Item Name (obtained from the uppercase format of ItemName) for every item that has the same total number of items bought on different purchase transactions as the item with ItemID 'IT004'.(ALIAS SUBQUERY)*/
SELECT 
	CONCAT('Item', RIGHT(mi.ItemID,3)) AS 'Item No',
	DifferentItemsBought,
	UPPER(ItemName) AS 'Item Name'
	FROM (
			SELECT
			ItemID,
			COUNT(DISTINCT PurchaseID) AS DifferentItemsBought
			FROM PurchaseDetail 
			GROUP BY ItemID
			HAVING COUNT(DISTINCT PurchaseID) = (SELECT COUNT(DISTINCT PurchaseID) 
				FROM PurchaseDetail 
				WHERE ItemID = 'IT004'
				GROUP BY ItemID
				)
				) AS [Item has the Same Total]
				JOIN MsItem mi ON mi.ItemID = [Item has the Same Total].ItemID

/*6.	Display Distributor Name (obtained from DistributorName in uppercase format), Minimum Item Quantity (obtained from the total minimum quantity of items bought in a purchase transaction), Total Item Quantity (obtained from the total quantity of items bought in a purchase transaction), PurchaseDate (obtained from the PurchaseDate in ‘Mon dd, yyyy’ format), Ship Arrived (obtained by adding 1 week to the PurchaseDate in ‘Mon dd, yyyy’ format) for every distributor with Minimum Item Quantity greater than 4 and Total Item Quantity greater than 10.(ALIAS SUBQUERY)*/
SELECT
    UPPER(md.DistributorName) AS [Distributor Name],
    MIN(Quantity) AS [Minimum Item Quantity],
    SUM(Quantity) AS [Total Item Quantity],
    CONVERT(VARCHAR, mp.PurchaseDate, 107) AS [PurchaseDate],
    CONVERT(VARCHAR, DATEADD(WEEK, 1, mp.PurchaseDate), 107) AS [Ship Arrived]
FROM MsPurchase mp
JOIN PurchaseDetail pd ON mp.PurchaseID = pd.PurchaseID
JOIN MsDistributor md ON md.DistributorID = mp.DistributorID,
	(
    SELECT
        md.DistributorName,
        MIN(PD.Quantity) AS MinQuantity,
        SUM(PD.Quantity) AS TotalQuantity,
        MIN(mp.PurchaseDate) AS PurchaseDate
    FROM PurchaseDetail pd
    JOIN MsPurchase mp ON pd.PurchaseID = mp.PurchaseID
	JOIN MsDistributor md ON mp.DistributorID = md.DistributorID
    GROUP BY md.DistributorID
    HAVING MIN(PD.Quantity) > 4 AND SUM(PD.Quantity) > 10
) 
SubQuery ON md.DistributorID = SubQuery.DistributorID;


/*7.	Display Transaction Date (obtained from TransactionDate in ‘Mon dd, yyyy’ format), Item Sold (obtained from the total item’s quantity sold), First Name (obtained from the first name of CustomerName) for every sales transaction where the total quantity of items bought by the customer is greater than 3 and the total number of different items bought is at least 2.(ALIAS SUBQUERY)*/
SELECT
    CONVERT(VARCHAR, SubQuery.TransactionDate, 107) AS [Transaction Date],
    SubQuery.TotalItemsSold AS [Item Sold],
    C.CustomerName AS [First Name]
FROM MsCustomer C,
	(
    SELECT
        ST.CustomerID,
        ST.TransactionDate,
        SUM(TD.Quantity) AS TotalItemsSold,
        COUNT(DISTINCT TD.ItemID) AS DifferentItemsBought
    FROM SalesTransaction ST
    JOIN TransactionDetail TD ON ST.TransactionID = TD.TransactionID
    GROUP BY ST.CustomerID, ST.TransactionDate
    HAVING SUM(TD.Quantity) > 3 AND COUNT(DISTINCT TD.ItemID) >= 2
) SubQuery ON C.CustomerID = SubQuery.CustomerID;


/*8.	Display Staff Name (obtained from StaffName in uppercase format), Staff Salary (obtained by adding ‘Rp ‘ to the front of StaffSalary and ending with ‘,00’), Maximum Price Item Sold (obtained by adding ‘Rp ‘ to the front of maximum total of item’s price multiplied by quantity and ending with ‘,00’), Average Staff Salary (obtained by adding ‘Rp ‘ to the front of  the average of all StaffSalary and ending with ‘,00’) for every staff with StaffSalary lower than the average of all StaffSalary and an even numbered StaffID.(ALIAS SUBQUERY)*/
SELECT 
    UPPER(StaffName) AS StaffName,
    CONCAT('Rp ', StaffSalary, ',00') AS StaffSalary,
    x.MaximumPriceItemSold,
    CONCAT('Rp ', CAST(AVG(StaffSalary) AS bigint), ',00') AS AvgStaffSalary
FROM MsStaff ms, (
	SELECT 
	st.StaffID,
	CONCAT('Rp', CAST(MAX(mi.ItemPrice*pd.Quantity) AS bigint), '00') AS 'MaximumPriceItemSold'
	FROM SalesTransaction st
	JOIN MsPurchase mp ON st.StaffID = mp.StaffID
	JOIN PurchaseDetail pd ON mp.PurchaseID = pd.PurchaseID
	JOIN MsItem mi ON pd.ItemID = mi.ItemID
	GROUP BY st.StaffID
	)x
WHERE x.StaffID = ms.StaffID AND CAST(RIGHT(ms.StaffID,3) AS INT) % 2 = 0
GROUP BY UPPER(ms.StaffName), ms.StaffSalary, x.MaximumPriceItemSold
HAVING ms.StaffSalary < AVG(ms.StaffSalary)

/*9.	Create a view named ‘Customer Transaction’ to display CustomerName, Staff (obtained by combining the StaffID and StaffName in uppercase format with a space in between), Item Bought (obtained from the total number of different items bought), Minimum Qty Bought (obtained from the minimum quantity of items bought by the customer), TransactionID for every transaction with CustomerGender of ‘Male’ and Minimum Qty Bought of at least 2.*/
GO
CREATE VIEW CustomerTransaction AS
SELECT 
    CustomerName,
    CONCAT(s.StaffID, ' ', UPPER(s.StaffName)) AS Staff,
    COUNT(DISTINCT ItemID) AS ItemBought,
    MIN(Quantity) AS MinimumQtyBought,  
	st.TransactionID
FROM SalesTransaction st
JOIN TransactionDetail td ON St.TransactionID = td.TransactionID
JOIN MsStaff s ON s.StaffID = st.StaffID
JOIN MsCustomer mc ON mc.CustomerID = st.CustomerID
WHERE CustomerGender = 'Male'
GROUP BY CustomerName, s.StaffID, StaffName, st.TransactionID;
GO

/*10.	Create a view named ‘Staff Bonus’ to display Year (obtained from the year of TransactionDate), StaffName, StaffAddress, StaffGender, Items Sold (obtained from the total quantity of items sold), Staff Salary (obtained by adding ‘Rp. ‘ in front of StaffSalary and ending with ‘,-‘), Bonus (obtained by adding 'Rp. ' in front of 10% of the StaffSalary and ending with ',-'), Salary After Bonus (obtained by adding StaffSalary and Bonus) for every sales transaction done in the year 2024 and total of different items sold is at least 2.*/
CREATE VIEW StaffBonus AS
SELECT 
    YEAR(TransactionDate) AS Year,
	StaffName,
    StaffAddress,
    StaffGender,
    SUM(Quantity) AS ItemsSold,
    CONCAT('Rp. ', StaffSalary, ',-') AS StaffSalary,
    CONCAT('Rp. ', 0.1 * StaffSalary, ',-') AS Bonus,
    CONCAT('Rp. ', CAST(StaffSalary + (StaffSalary * 0.1) AS DECIMAL(10,2)), ',-') AS SalaryAfterBonus
FROM SalesTransaction st
JOIN TransactionDetail td ON st.TransactionID = td.TransactionID
JOIN MsStaff ms ON st.StaffID = ms.StaffID
WHERE YEAR(TransactionDate) = 2024
GROUP BY YEAR(TransactionDate), StaffName, StaffAddress, StaffGender, StaffSalary
HAVING COUNT(DISTINCT ItemID) >= 2;
