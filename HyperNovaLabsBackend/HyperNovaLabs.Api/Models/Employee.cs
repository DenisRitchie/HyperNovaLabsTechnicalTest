namespace HyperNovaLabs.Api.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;
    using System.Threading.Tasks;

    [Table(nameof(Employee))]
    public class Employee
    {
        [Key]
        [StringLength(32)]
        public string Identification { get; set; }

        [Required]
        [StringLength(64)]
        public string Name { get; set; }

        [Required]
        [StringLength(32)]
        public string Department { get; set; }

        [Required]
        [StringLength(32)]
        public string Position { get; set; }

        [Required]
        [StringLength(64)]
        public string Supervisor { get; set; }

        public ICollection<Bill> Bills { get; set; }
    }
}
