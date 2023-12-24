-- 2. Query to create the database system
CREATE DATABASE MloatedCorps;
USE MloatedCorps;

-- Table MsStaff
CREATE TABLE MsStaff(
	StaffID CHAR(5) PRIMARY KEY CHECK (StaffID REGEXP '^ST[0-9][0-9][0-9]$') NOT NULL,
	StaffName VARCHAR(50) NOT NULL,
	StaffGender VARCHAR(50) NOT NULL,
	StaffAddress VARCHAR(255) NOT NULL,
	StaffSalary DECIMAL(10,1) NOT NULL,
	StaffPhoneNumber NUMERIC(15) NOT NULL
);

	-- 3. Query to insert data into tables
-- inserting data into Staff table minimal 10
INSERT INTO MsStaff VALUES
('ST001', 'John Doe', 'Male', '123 Main Street', 50000.0, 08213238293),
('ST002', 'Joanne Asher', 'Female', '11 Holo Street', 55000.0, 08372374234),
('ST003', 'Vannesia May', 'Female', '13 Mate Street', 65000.0, 082134724328),
('ST004', 'Ingrid Marbella', 'Female', '23 Matoa Street', 75500.0, 083645274937),
('ST005', 'Asher Don', 'Male', '25 Apple Street', 75400.0, 1356320000),
('ST006', 'Melati Rose', 'Female', '75 Mangosteen Street', 65000.0, 084637893746),
('ST007', 'Don Frederick', 'Male', '13 Palem Lestari Street', 65000.0, 0836254729),
('ST008', 'Lisa Manoban', 'Female', '13 Taman Kencana Street', 65000.0, 0842198765),
('ST009', 'Julita Sari', 'Female', '13 Menceng Street', 65000.0, 0865368937),
('ST010', 'Sehun Ganteng', 'Male', '20 Cikarang Street', 65000.0, 08653689374),
('ST011', 'Jeno Jeniaz', 'Male', '35 Bekasi Galaxy Street', 65000.0, 08133749374),
('ST012', 'Luhan Gonzali', 'Male', '58 Seoul Street', 65000.0, 0812786435),
('ST013', 'Bule Toxic', 'Female', '30 Durian Street', 65000.0, 0853246806),
('ST014', 'Joshua Adhiguna', 'Male', '60 Lamb Street', 65000.0, 08432468654),
('ST015', 'Fadil Jaidi', 'Male', '45 Semanan Street', 65000.0, 08432567654),
('ST016', 'Rio Melati', 'Male', '45 Semanan Street', 65000.0, 08122111123),
('ST017', 'Leo Alfaris', 'Male', '45 Semanan Street', 65000.0, 0834673433),
('ST018', 'Ignatius Hubert', 'Male', '45 Semanan Street', 65000.0, 0843277545);


-- Table MsCustomer
CREATE TABLE MsCustomer(
	CustomerID CHAR(5) PRIMARY KEY CHECK (CustomerID REGEXP '^CU[0-9][0-9][0-9]$') NOT NULL,
	CustomerName VARCHAR(255) CHECK(CustomerName LIKE 'Mr%' OR CustomerName LIKE 'Mrs%') NOT NULL,
	CustomerGender VARCHAR(25) NOT NULL,
	CustomerAddress VARCHAR(225) CHECK(CustomerAddress LIKE '%Street%') NOT NULL,
	CustomerPhoneNumber NUMERIC(15) NOT NULL
);

INSERT INTO MsCustomer VALUES 
('CU001', 'Mr.Dodo', 'Male', '300 Bohuat Street', 0823814077),
('CU002', 'Mr.Deni', 'Male', '23 Paul Parkway Street',0826813493),
('CU003', 'Mrs.Pethia', 'Female', '290 Badland loby Street',0837493748),
('CU004', 'Mrs.Ironman', 'Female', '51745 Bowton river Street',08121212),
('CU005', 'Mr.Hulk', 'Male', '200 Old Castle Center Street',081434324),
('CU006', 'Mr.Nani', 'Male', '3455 City Yellow Court Street',081324323),
('CU007', 'Mrs.Nande', 'Female', '20 Kolor Goodland Park Street',0832233822),
('CU008', 'Mrs.Doko', 'Female', '1 Sea Street',0822113232),
('CU009', 'Mr.Mokondo', 'Male', '317 Noban Point Street',08232233),
('CU010', 'Mr.Hutao', 'Male', '036 Ingrid Plaza Street',087283728),
('CU011', 'Mr.Lesbon', 'Male', '1070 Office Drive Street',082134783),
('CU012', 'Mr.Benjamin', 'Male', '90 Li Junction Street',0824903764);


-- Table Membership
CREATE TABLE MsMembership(
    MemberID CHAR(5) PRIMARY KEY CHECK (MemberID REGEXP '^ME[0-9][0-9][0-9]$'),
    CustomerID CHAR(5) CHECK (CustomerID REGEXP '^CU[0-9][0-9][0-9]$'),
    StarDateMember DATE NOT NULL,
    EndDateMember DATE NOT NULL,
    FOREIGN KEY (CustomerID) REFERENCES MsCustomer(CustomerID)
);

INSERT INTO MsMembership VALUES 
('ME001', 'CU001', '2023-04-15', '2023-05-15'),
('ME002', 'CU002', '2023-04-26', '2023-04-27'),
('ME003', 'CU003', '2023-04-06', '2023-04-09'),
('ME004', 'CU004', '2023-04-07', '2023-04-10'),
('ME005', 'CU005', '2023-04-08', '2023-04-11'),
('ME006', 'CU006', '2023-04-09', '2023-04-12'),
('ME007', 'CU007', '2023-04-10', '2023-04-23'),
('ME008', 'CU008', '2023-04-11', '2023-04-16'),
('ME009', 'CU009', '2023-04-12', '2023-04-21'),
('ME010', 'CU010', '2023-04-13', '2023-04-19'),
('ME011', 'CU011', '2023-04-14', '2023-04-25'),
('ME012', 'CU012', '2023-04-15', '2023-04-28');


-- Table Distributor
CREATE TABLE MsDistributor(
	DistributorID CHAR(5) PRIMARY KEY CHECK (DistributorID REGEXP '^DI[0-9][0-9][0-9]$'),
	DistributorName VARCHAR(225) CHECK(LENGTH(DistributorName) > 4) NOT NULL
);

INSERT INTO MsDistributor 
VALUES
    ('DI001', 'ABC Distributors'),
    ('DI002', 'XYZ Suppliers'),
    ('DI003', 'LMN Wholesalers'),
    ('DI004', 'PQR Distributors'),
    ('DI005', 'JKL Suppliers'),
    ('DI006', 'DEF Distributors'),
    ('DI007', 'MNO Suppliers'),
    ('DI008', 'GHI Wholesalers'),
    ('DI009', 'STU Distributors'),
    ('DI010', 'VWX Suppliers'),
    ('DI011', 'ZYX Wholesalers');


-- Table Item Category
CREATE TABLE ItemCategory(
	CategoryID CHAR(5) PRIMARY KEY CHECK (CategoryID REGEXP '^CI[0-9][0-9][0-9]$'),
	CategoryName VARCHAR(225) NOT NULL
);

INSERT INTO ItemCategory 
VALUES
    ('CI001', 'Electronics'),
    ('CI002', 'Clothing'),
    ('CI003', 'Home and Garden'),
    ('CI004', 'Books'),
    ('CI005', 'Health and Beauty'),
    ('CI006', 'Toys and Games'),
    ('CI007', 'Sports and Outdoors'),
    ('CI008', 'Automotive'),
    ('CI009', 'Jewelry'),
    ('CI010', 'Office Supplies'),
    ('CI011', 'Food and Beverages');


-- Table Item
CREATE TABLE MsItem(
    ItemID CHAR(5) PRIMARY KEY CHECK (ItemID REGEXP '^IT[0-9][0-9][0-9]$'),
    CategoryID CHAR(5) CHECK (CategoryID REGEXP '^CI[0-9][0-9][0-9]$'),
    ItemName VARCHAR(50) NOT NULL,
    ItemPrice DECIMAL(10, 1) CHECK(ItemPrice > 0) NOT NULL,
    ItemStock VARCHAR(50) CHECK(ItemStock >= 0) NOT NULL,
    FOREIGN KEY (CategoryID) REFERENCES ItemCategory(CategoryID)
);

INSERT INTO MsItem 
VALUES
    ('IT001', 'CI001', 'Smartphone', 79.8, 50),
    ('IT002', 'CI002', 'T-Shirt', 19.79, 100),
    ('IT003', 'CI003', 'Gardening Tools', 49.9, 30),
    ('IT004', 'CI004', 'Novel', 15.7, 75),
    ('IT005', 'CI005', 'Shampoo', 10.2, 200),
    ('IT006', 'CI006', 'Board Game', 24.5, 40),
    ('IT007', 'CI007', 'Running Shoes', 89.8, 20),
    ('IT008', 'CI008', 'Car Oil', 37.9, 60),
    ('IT009', 'CI009', 'Gold Necklace', 29.6, 10),
    ('IT010', 'CI010', 'Printer Paper', 78.9, 150),
    ('IT011', 'CI011', 'Chocolate Bar', 21.8, 500);

-- Table Purchase
CREATE TABLE MsPurchase(
    PurchaseID CHAR(5) PRIMARY KEY CHECK (PurchaseID REGEXP '^PH[0-9][0-9][0-9]'),
    DistributorID CHAR(5) CHECK (DistributorID REGEXP '^DI[0-9][0-9][0-9]'),
    StaffID CHAR(5) CHECK (StaffID REGEXP '^ST[0-9][0-9][0-9]'),
    PurchaseDate DATE NOT NULL,
    FOREIGN KEY (DistributorID) REFERENCES MsDistributor(DistributorID),
    FOREIGN KEY (StaffID) REFERENCES MsStaff(StaffID)
);

INSERT INTO MsPurchase 
VALUES
    ('PH001', 'DI011', 'ST001', '2023-12-01'),
    ('PH002', 'DI010', 'ST002', '2023-12-05'),
    ('PH003', 'DI009', 'ST003', '2023-12-10'),
    ('PH004', 'DI008', 'ST004', '2023-12-15'),
    ('PH005', 'DI007', 'ST005', '2023-12-20'),
    ('PH006', 'DI006', 'ST006', '2023-12-25'),
    ('PH007', 'DI005', 'ST007', '2023-12-02'),
    ('PH008', 'DI004', 'ST008', '2023-12-08'),
    ('PH009', 'DI003', 'ST009', '2023-12-12'),
    ('PH010', 'DI002', 'ST010', '2023-12-18'),
    ('PH011', 'DI001', 'ST011', '2023-12-22');

-- Table Purchase Detail
CREATE TABLE PurchaseDetail(
    PurchaseDetailID VARCHAR(5) PRIMARY KEY CHECK (PurchaseDetailID REGEXP '^PD[0-9][0-9][0-9]$'),
    PurchaseID CHAR(5) CHECK (PurchaseID REGEXP '^PH[0-9][0-9][0-9]$'),
    ItemID CHAR(5) CHECK (ItemID REGEXP '^IT[0-9][0-9][0-9]$'),
    Quantity INT NOT NULL,
    FOREIGN KEY (PurchaseID) REFERENCES MsPurchase(PurchaseID),
    FOREIGN KEY (ItemID) REFERENCES MsItem(ItemID)
);

INSERT INTO PurchaseDetail (PurchaseDetailID, PurchaseID, ItemID, Quantity)
VALUES
    ('PD001', 'PH011', 'IT001', 15),
    ('PD002', 'PH010', 'IT002', 31),
    ('PD003', 'PH009', 'IT003', 27),
    ('PD004', 'PH008', 'IT004', 88),
    ('PD005', 'PH007', 'IT005', 64),
    ('PD006', 'PH006', 'IT006', 54),
    ('PD007', 'PH005', 'IT007', 71),
    ('PD008', 'PH004', 'IT008', 41),
    ('PD009', 'PH003', 'IT009', 17),
    ('PD010', 'PH002', 'IT010', 31),
    ('PD011', 'PH001', 'IT011', 35);

-- Table Sales Transaction
CREATE TABLE SalesTransaction(
    TransactionID CHAR(5) PRIMARY KEY CHECK (TransactionID REGEXP '^TH[0-9][0-9][0-9]$'),
    StaffID CHAR(5) CHECK (StaffID REGEXP '^ST[0-9][0-9][0-9]$'),
    CustomerID CHAR(5) CHECK (CustomerID REGEXP '^CU[0-9][0-9][0-9]$'),
    PaymentType VARCHAR(50) CHECK (PaymentType IN ('Cash', 'SirQ', 'Transfer Bank')),
    TransactionDate DATE NOT NULL,
    FOREIGN KEY (StaffID) REFERENCES MsStaff(StaffID),
    FOREIGN KEY (CustomerID) REFERENCES MsCustomer(CustomerID)
);

INSERT INTO SalesTransaction 
VALUES
    ('TH001', 'ST001', 'CU001', 'Cash', '2024-01-15'),
    ('TH002', 'ST002', 'CU002', 'Transfer Bank', '2024-02-20'),
    ('TH003', 'ST003', 'CU003', 'SirQ', '2024-03-10'),
    ('TH004', 'ST004', 'CU004', 'Cash', '2024-04-05'),
    ('TH005', 'ST005', 'CU005', 'Transfer Bank', '2024-05-18'),
    ('TH006', 'ST006', 'CU006', 'Cash', '2024-06-22'),
    ('TH007', 'ST007', 'CU007', 'SirQ', '2024-07-07'),
    ('TH008', 'ST008', 'CU008', 'Transfer Bank', '2024-08-12'),
    ('TH009', 'ST009', 'CU009', 'Cash', '2024-09-28'),
    ('TH010', 'ST010', 'CU010', 'SirQ', '2024-10-15'),
    ('TH011', 'ST011', 'CU011', 'Transfer Bank', '2024-11-20');

-- Sales Transaction Detail
CREATE TABLE TransactionDetail(
    SalesDetailID CHAR(5) PRIMARY KEY CHECK (SalesDetailID REGEXP '^SD[0-9][0-9][0-9]$'),
    TransactionID CHAR(5) CHECK (TransactionID REGEXP '^TH[0-9][0-9][0-9]$'),
    ItemID CHAR(5) CHECK (ItemID REGEXP '^IT[0-9][0-9][0-9]$'),
    Quantity INT NOT NULL,
    FOREIGN KEY (TransactionID) REFERENCES SalesTransaction(TransactionID),
    FOREIGN KEY (ItemID) REFERENCES MsItem(ItemID)
);

INSERT INTO TransactionDetail 
VALUES
    ('SD001', 'TH001', 'IT001', 21),
    ('SD002', 'TH001', 'IT002', 67),
    ('SD003', 'TH002', 'IT003', 34),
    ('SD004', 'TH002', 'IT004', 27),
    ('SD005', 'TH003', 'IT001', 13),
    ('SD006', 'TH003', 'IT002', 72),
    ('SD007', 'TH004', 'IT003', 11),
    ('SD008', 'TH004', 'IT004', 32),
    ('SD009', 'TH005', 'IT001', 42),
    ('SD010', 'TH005', 'IT002', 51),
    ('SD011', 'TH006', 'IT003', 83),
    -- ('SD012', 'TH042', 'IT006', 42),
    -- ('SD013', 'TH044', 'IT007', 11),
    -- ('SD014', 'TH045', 'IT008', 14),
    -- ('SD015', 'TH046', 'IT009', 33),
    -- ('SD016', 'TH047', 'IT010', 52),
    -- ('SD017', 'TH048', 'IT011', 10),
    -- ('SD018', 'TH049', 'IT012', 31),
    -- ('SD019', 'TH050', 'IT013', 26),
    -- ('SD020', 'TH051', 'IT014', 40),
    -- ('SD021', 'TH052', 'IT015', 38),
    -- ('SD022', 'TH053', 'IT016', 82),
    -- ('SD023', 'TH054', 'IT017', 71),
    -- ('SD024', 'TH055', 'IT018', 45),
    -- ('SD025', 'TH056', 'IT025', 30);

/*	Master table must be filled with more than or equals 10 data.
	Transaction table must be filled with more than or equals 15 data.
	Transaction detail table must be filled with more than or equals 25 data.
	'Cash', 'SirQ', 'Transfer Bank'
	*/
-- 4. Query to simulate the transactions processes
-- Example for simulating a sales transaction minimal 15
INSERT INTO SalesTransaction (TransactionID, StaffID, CustomerID, PaymentType, TransactionDate)
VALUES
('TH001', 'ST001', 'CU020', 'Cash', '2023-01-15'),
('TH002', 'ST002', 'CU019', 'SirQ', '2023-02-24'),
('TH003', 'ST003', 'CU018', 'Cash', '2023-03-04'),
('TH004', 'ST004', 'CU017', 'Transfer Bank', '2023-04-17'),
('TH005', 'ST005', 'CU016', 'SirQ', '2023-06-11'),
('TH006', 'ST006', 'CU015', 'Transfer Bank', '2023-05-23'),
('TH007', 'ST007', 'CU014', 'Cash', '2023-07-01'),
('TH008', 'ST008', 'CU013', 'Transfer Bank', '2024-01-01'),
('TH009', 'ST009', 'CU012', 'Cash', '2023-08-20'),
('TH010', 'ST010', 'CU011', 'Transfer Bank', '2024-12-11'),
('TH011', 'ST011', 'CU010', 'Cash', '2023-09-12'),
('TH012', 'ST012', 'CU009', 'SirQ', '2023-10-02'),
('TH013', 'ST013', 'CU008', 'Cash', '2023-11-11'),
('TH014', 'ST014', 'CU007', 'Transfer Bank', '2024-05-14'),
('TH015', 'ST015', 'CU006', 'SirQ', '2024-03-21'),
('TH016', 'ST016', 'CU005', 'Cash', '2024-07-16'),
('TH017', 'ST017', 'CU004', 'Transfer Bank', '2023-01-01'),
('TH018', 'ST018', 'CU003', 'SirQ', '2023-05-31'),
('TH019', 'ST019', 'CU002', 'Cash', '2024-03-01'),
('TH020', 'ST020', 'CU001', 'Transfer Bank', '2023-12-12');

-- Repeat for other transactions
SELECT * from SalesTransaction;
SELECT * from TransactionDetail;
SELECT * from MsCustomer;
SELECT * from MsStaff;
SELECT * from MsMembership;
SELECT * from MsDistributor;
SELECT * from ItemCategory;
SELECT * from MsItem;
SELECT * from MsPurchase;
SELECT * from PurchaseDetail;

-- 5. Query to answer the 10 cases